import java.util.*;

class u00g13{
    public static Scanner sc = new Scanner(System.in);
    public static void main (String[] args){
        int tamanho = 0;
        int soma = 0;
        int media = 0;
        int i = 0;

        System.out.print("Quantidade de numeros: ");
        tamanho = sc.nextInt();
        int num[] = new int[tamanho];
        for (i = 0; i < tamanho; i++){
            num[i] = sc.nextInt();
        }
        for (i = 0; i < tamanho; i++){
            soma = soma + num[i];
        }
        //System.out.println(soma);
        media = soma / tamanho;
        System.out.println("Media = " + media);
        for (i = 0; i < tamanho; i++){
            if (num[i]>media){
                System.out.println("Acima da media " + num[i]);
            }
        }
        sc.close();
    }
}