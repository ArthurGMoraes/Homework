// key 5ffb92356f014983b19931ed3546cc05
// url https://ex4.cognitiveservices.azure.com/

// probelema:
/*Instalar a biblioteca de clientes
Depois de criar um projeto, instale a biblioteca de clientes clicando com o botão direito do mouse na 
solução do projeto no Gerenciador de Soluções e selecionando Gerenciar Pacotes NuGet. No gerenciador de pacotes aberto, 
selecione Procurar, marque Incluir pré-lançamento e pesquise Microsoft.Azure.CognitiveServices.Vision.Face. Selecione a versão mais 
recente e escolha Instalar.
*/

// codigo disponibilizado
import com.microsoft.azure.cognitiveservices.vision.faceapi.*;
import com.microsoft.azure.cognitiveservices.vision.faceapi.models.*;

import java.util.*;
import java.io.IOException;
import java.net.URI;
import java.util.concurrent.TimeUnit;

public class FaceQuickstart {
    static String personGroupId = UUID.randomUUID().toString();

    // URL path for the images.
    static final String IMAGE_BASE_URL = "https://raw.githubusercontent.com/Azure-Samples/cognitive-services-sample-data-files/master/Face/images/";

    // From your Face subscription in the Azure portal, get your subscription key and endpoint.
    static final String SUBSCRIPTION_KEY = "5ffb92356f014983b19931ed3546cc05";
    static final String ENDPOINT = "https://ex4.cognitiveservices.azure.com/";

    public static void main(String[] args) {
        // Recognition model 4 was released in February 2021.
        // It is recommended since its accuracy is improved on faces wearing masks compared with model 3,
        // and its overall accuracy is improved compared with models 1 and 2.
        final String RECOGNITION_MODEL4 = RecognitionModel.RECOGNITION_04;

        // Authenticate.
        IFaceClient client = Authenticate(ENDPOINT, SUBSCRIPTION_KEY);

        // Identify - recognize a face(s) in a person group (a person group is created in this example).
        try {
            IdentifyInPersonGroup(client, IMAGE_BASE_URL, RECOGNITION_MODEL4).get();
        } catch (Exception e) {
            e.printStackTrace();
        }

        System.out.println("End of quickstart.");
    }

    /*
     * AUTHENTICATE
     * Uses subscription key and region to create a client.
     */
    public static IFaceClient Authenticate(String endpoint, String key) {
        return FaceClient.builder().endpoint(endpoint).credential(new ApiKeyCredentials(key)).buildClient();
    }

    // Detect faces from image URL for recognition purposes. This is a helper method for other functions in this quickstart.
    // Parameter `returnFaceId` of `DetectWithUrlAsync` must be set to `true` (by default) for recognition purposes.
    // Parameter `FaceAttributes` is set to include the QualityForRecognition attribute.
    // Recognition model must be set to recognition_03 or recognition_04 as a result.
    // Result faces with insufficient quality for recognition are filtered out.
    // The field `faceId` in returned `DetectedFace`s will be used in Face - Face - Verify and Face - Identify.
    // It will expire 24 hours after the detection call.
    private static List<DetectedFace> DetectFaceRecognize(IFaceClient faceClient, String url, String recognitionModel) throws Exception {
        // Detect faces from image URL. Since only recognizing, use recognition model 1.
        // We use detection model 3 because we are not retrieving attributes.
        List<DetectedFace> sufficientQualityFaces = new ArrayList<>();

        DetectFaceWithUrlOptions options = new DetectFaceWithUrlOptions();
        options.withRecognitionModel(recognitionModel);
        options.withDetectionModel(DetectionModel.DETECTION_03);
        options.withReturnFaceAttributes(Collections.singletonList(FaceAttributeType.QUALITY_FOR_RECOGNITION));

        List<DetectedFace> detectedFaces = faceClient.face().detectWithUrl(url, options);

        for (DetectedFace detectedFace : detectedFaces) {
            FaceAttributes faceAttributes = detectedFace.faceAttributes();
            Float faceQualityForRecognition = faceAttributes.qualityForRecognition();
            if (faceQualityForRecognition != null && faceQualityForRecognition >= QualityForRecognition.MEDIUM) {
                sufficientQualityFaces.add(detectedFace);
            }
        }

        System.out.println(detectedFaces.size() + " face(s) with " + sufficientQualityFaces.size() + " having sufficient quality for recognition detected from image `" + Paths.get(new URI(url).getPath()).getFileName() + "`");

        return sufficientQualityFaces;
    }

    /*
     * IDENTIFY FACES
     * To identify faces, you need to create and define a person group.
     * The Identify operation takes one or several face IDs from DetectedFace or PersistedFace and a PersonGroup and returns
     * a list of Person objects that each face might belong to. Returned Person objects are wrapped as Candidate objects,
     * which have a prediction confidence value.
     */
    public static void IdentifyInPersonGroup(IFaceClient client, String url, String recognitionModel) throws Exception {
        System.out.println("========IDENTIFY FACES========");
        System.out.println();

        // Create a dictionary for all your images, grouping similar ones under the same key.
        Map<String, String[]> personDictionary = new HashMap<>();
        personDictionary.put("Family1-Dad", new String[]{"Family1-Dad1.jpg", "Family1-Dad2.jpg"});
        personDictionary.put("Family1-Mom", new String[]{"Family1-Mom1.jpg", "Family1-Mom2.jpg"});
        personDictionary.put("Family1-Son", new String[]{"Family1-Son1.jpg", "Family1-Son2.jpg"});
        personDictionary.put("Family1-Daughter", new String[]{"Family1-Daughter1.jpg", "Family1-Daughter2.jpg"});
        personDictionary.put("Family2-Lady", new String[]{"Family2-Lady1.jpg", "Family2-Lady2.jpg"});
        personDictionary.put("Family2-Man", new String[]{"Family2-Man1.jpg", "Family2-Man2.jpg"});

        // A group photo that includes some of the persons you seek to identify from your dictionary.
        String sourceImageFileName = "identification1.jpg";

        // Create a person group.
        System.out.println("Create a person group (" + personGroupId + ").");
        client.personGroup().create(personGroupId, personGroupId, recognitionModel);
        // The similar faces will be grouped into a single person group person.
        for (String groupedFace : personDictionary.keySet()) {
            // Limit TPS
            TimeUnit.MILLISECONDS.sleep(250);
            Person person = client.personGroupPerson().create(personGroupId, groupedFace);
            System.out.println("Create a person group person '" + groupedFace + "'.");

            // Add face to the person group person.
            for (String similarImage : personDictionary.get(groupedFace)) {
                System.out.println("Check whether image is of sufficient quality for recognition");
                List<DetectedFace> detectedFaces1 = DetectFaceRecognize(client, url + similarImage, recognitionModel);
                boolean sufficientQuality = true;
                for (DetectedFace face1 : detectedFaces1) {
                    Float faceQualityForRecognition = face1.faceAttributes().qualityForRecognition();
                    // Only "high" quality images are recommended for person enrollment
                    if (faceQualityForRecognition != null && faceQualityForRecognition != QualityForRecognition.HIGH) {
                        sufficientQuality = false;
                        break;
                    }
                }

                if (!sufficientQuality) {
                    continue;
                }

                // Add face to the person group
                System.out.println("Add face to the person group person(" + groupedFace + ") from image `" + similarImage + "`");
                client.personGroupPerson().addFaceFromUrl(personGroupId, person.personId(), url + similarImage, similarImage);
            }
        }

        // Start to train the person group.
        System.out.println();
        System.out.println("Train person group " + personGroupId + ".");
        client.personGroup().train(personGroupId);

        // Wait until the training is completed.
        while (true) {
            TimeUnit.SECONDS.sleep(1);
            TrainingStatus trainingStatus = client.personGroup().getTrainingStatus(personGroupId);
            System.out.println("Training status: " + trainingStatus.status() + ".");
            if (trainingStatus.status() == TrainingStatusType.SUCCEEDED) {
                break;
            }
        }
        System.out.println();

        List<UUID> sourceFaceIds = new ArrayList<>();
        // Detect faces from source image URL.
        List<DetectedFace> detectedFaces = DetectFaceRecognize(client, url + sourceImageFileName, recognitionModel);

        // Add detected faceId to sourceFaceIds.
        for (DetectedFace detectedFace : detectedFaces) {
            sourceFaceIds.add(detectedFace.faceId());
        }

        // Identify the faces in a person group.
        IdentifyResult[] identifyResults = client.face().identify(sourceFaceIds, personGroupId);

        for (IdentifyResult identifyResult : identifyResults) {
            if (identifyResult.candidates().isEmpty()) {
                System.out.println("No person is identified for the face in: " + sourceImageFileName + " - " + identifyResult.faceId() + ",");
                continue;
            }
            Person person = client.personGroupPerson().get(personGroupId, identifyResult.candidates().get(0).personId());
            System.out.println("Person '" + person.name() + "' is identified for the face in: " + sourceImageFileName + " - " + identifyResult.faceId() +
                    ", confidence: " + identifyResult.candidates().get(0).confidence());

            VerifyResult verifyResult = client.face().verifyFaceToPerson(identifyResult.faceId(), person.personId(), personGroupId);
            System.out.println("Verification result: is a match? " + verifyResult.isIdentical() + ". confidence: " + verifyResult.confidence());
        }
        System.out.println();
    }
}
