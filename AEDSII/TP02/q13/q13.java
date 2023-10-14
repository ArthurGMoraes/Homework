class q13{
    public static int comp = 0;
    public static int trocas = 0;
    public static int[] ids = new int[500];
    public static String[] unis = new String[4000];
    public static String[] nomes = new String[4000];
    public static Arq arq = new Arq();
    public static MyIO myIo = new MyIO();

    public static void swap(int i, int j) {
        int temp = ids[i];
        ids[i] = ids[j]; trocas++;
        ids[j] = temp; trocas++;
    }

    public static void lerNomes(){
        arq.openRead("/tmp/players.csv");
        int i = 0;
        String temp;
        while(arq.hasNext() == true){
            comp++;
            temp = arq.readLine();
            String[] parts = temp.split(",");
            nomes[i] = parts[1];
            i++;
        }
        arq.close();
    }

    public static void lerUnis(){
        arq.openRead("/tmp/players.csv");
        int i = 0;
        String temp;
        while(arq.hasNext() == true){
            comp++;
            temp = arq.readLine();
            String[] parts = temp.split(",");
            unis[i] = parts[4];
            //myIo.println(unis[i]);
            i++;
        }
        arq.close();
    }

    public static int compUnis(int prim, int sec){
        if (prim < 0 || prim >= unis.length || sec < 0 || sec >= unis.length) {
        return 0; // Handle out of bounds indices
    }
        int i = 0;
        int result = -1;
        String a = unis[prim + 1];
        String b = unis[sec + 1];
        String c = nomes[prim + 1];;
        String d = nomes[sec + 1];;

        //myIo.println(a + " " + b);

        
        if (a.compareTo(b) > 0){
            result = 1;
        } else if (a.compareTo(b) == 0){
            //result = 0;
            result = c.compareTo(d);
        }
        
        return result;
    } 



     public static void ordenar(int k) {
        mergesort(0, k-1);
    }

    private static void mergesort(int esq, int dir) {
        if (esq < dir){
            int meio = (esq + dir) / 2;
            mergesort(esq, meio);
            mergesort(meio + 1, dir);
            intercalar(esq, meio, dir);
        }
   }

    public static void intercalar(int esq, int meio, int dir){
        int n1, n2, i, j, k;

        //Definir tamanho dos dois subarrays
        n1 = meio-esq+1;
        n2 = dir - meio;

        int[] a1 = new int[n1+2];
        int[] a2 = new int[n2+2];

        //Inicializar primeiro subarray
        for(i = 0; i < n1; i++){
            a1[i] = ids[esq+i];
           //myIo.print(a1[i] + " ");
        }
        //myIo.println(" ");
        //Inicializar segundo subarray
        for(j = 0; j < n2; j++){
            a2[j] = ids[meio+j+1];
           //myIo.print(a2[j] + " ");
        }

        //Sentinela no final dos dois arrays
        a1[i+1] = a2[j+1] = 0x7FFFFFFF;

        //Intercalacao propriamente dita
      for(i = j = 0, k = esq; k <= dir; k++){
        //ids[k] = (compUnis(a1[i], a2[j]) <= 0) ? a1[i++] : a2[j++];
        if(compUnis(a1[i], a2[j]) <= 0){
            if(a1[i] != 0){
                ids[k] = a1[i++];
            }
        } else {
            if(a2[j] != 0 || ids){
                ids[k] = a2[j++];
            }
        }
      }
    }
    

    public static void ler(int num){
        arq.openRead("/tmp/players.csv");
        int i = 0;
        String str = "";
        //myIo.println(num);
        while(i < num + 1){
            comp++;
            arq.readLine();
            i++;
        }
        str = arq.readLine();
        //myIo.println(str + " " + i);
        str += " ";
        String[] parts = str.split(",");
        for (int k = 0; k < parts.length; k++) {
            //myIo.println(num + " " + parts[k]);
            if (parts[k].isEmpty() || parts[k].equals(" ")) {
                comp++;
                parts[k] = "nao informado";
            }
        } 
        int id = Integer.parseInt(parts[0]);
        String nome = parts[1];
        int altura = Integer.parseInt(parts[2]);
        int peso = Integer.parseInt(parts[3]);
        String cidadeNascimento = parts[6];
        String estadoNascimento = parts[7];
        int anoNascimento = Integer.parseInt(parts[5]);
        String universidade = parts[4];
        myIo.println("[" + id + " ## " + nome + " ## " + altura + " ## " + peso + " ## " + anoNascimento + " ## " + universidade + " ## " + cidadeNascimento + " ## " + estadoNascimento.trim() + "]");
        arq.close();
    }



    public static void main(String[] args){
        String id = "";
        String nome = "";
        int i = 0;
        int j = 0;
        int teste = 0;
        double inicio, fim;

        inicio = System.currentTimeMillis();
        do{
            id = myIo.readLine();
            if (!id.equalsIgnoreCase("FIM")){
                ids[i] = Integer.parseInt(id);
                i++;
            }
        } while (!id.equalsIgnoreCase("FIM"));
        lerNomes();
        lerUnis();
        ordenar(i);

        
        for (j = 0; j < i; j++){
            teste = ids[j];
            if(teste != 0){    // array preenchido com 0s
              ler(teste);
              comp++;
            }

        }
        fim = System.currentTimeMillis();
        
        String tempo = (fim-inicio)/1000 + "";
        String conteudo = "816479\t" + comp + "\t" + trocas + "\t" + tempo;
        //arq.openWriteClose("matrícula_mergesort.txt", conteudo);
    }
}