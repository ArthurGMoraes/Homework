class q09{
    public static int comp = 0;
    public static int trocas = 0;
    public static int[] ids = new int[500];
    public static int[] tamanhos = new int[4000];
    public static String[] nomes = new String[4000];
    public static Arq arq = new Arq();
    public static MyIO myIo = new MyIO();

    public static void swap(int i, int j) {
        int temp = ids[i];
        ids[i] = ids[j]; trocas++;
        ids[j] = temp; trocas++;
    }

    public static void lerNomes(){
        arq.openRead("players.csv");
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

    public static void lerTamanho(){
        arq.openRead("players.csv");
        int i = 0;
        String temp;
        arq.readLine();  // pular primeira linha
        while(arq.hasNext() == true){
            comp++;
            temp = arq.readLine();
            String[] parts = temp.split(",");
            tamanhos[i] = Integer.parseInt(parts[2]);
            i++;
        }
        arq.close();
    }

    public static int compTamanhos(int prim, int sec){
        int i = 0;
        int result = -1;
        int a = tamanhos[prim];
        int b = tamanhos[sec];
        String c = nomes[prim + 1];;
        String d = nomes[sec + 1];;

        //myIo.println(a + " " + b);

        if(a != 0 && b != 0){
            comp++;
            if(a>b){
                result = 1;
            } else if (a == b){
                result = c.compareTo(d);
            }
        }
        return result;
    } 



    public static void ordenar(int k) {
        //Alterar o vetor ignorando a posicao zero
        int[] tmp = new int[k+1];
        for(int i = 0; i < k; i++){
            tmp[i+1] = ids[i];
        }
        ids = tmp;

        //Contrucao do heap
        for(int tamHeap = 2; tamHeap <= k; tamHeap++){
            construir(tamHeap);
        }

        //Ordenacao propriamente dita
        int tamHeap = k;
        while(tamHeap > 1){
            swap(1, tamHeap--);
            reconstruir(tamHeap);
        }

        //Alterar o vetor para voltar a posicao zero
        tmp = ids;
        ids = new int[k];
        for(int i = 0; i < k; i++){
            ids[i] = tmp[i+1];
        }
    }


    public static void construir(int tamHeap){
        for(int i = tamHeap; i > 1 && compTamanhos(ids[i], ids[i/2]) > 0; i /= 2){
            //myIo.println("ok");
            swap(i, i/2);
        }
    }


    public static void reconstruir(int tamHeap){
        int i = 1;
        while(i <= (tamHeap/2)){
            int filho = getMaiorFilho(i, tamHeap);
            if(compTamanhos(ids[i], ids[filho]) < 0){
                swap(i, filho);
                i = filho;
            }else{
                i = tamHeap;
            }
        }
    }

    public static int getMaiorFilho(int i, int tamHeap){
        int filho;
        if (2*i == tamHeap || compTamanhos(ids[2*i], ids[2*i+1]) > 0){
            filho = 2*i;
        } else {
            filho = 2*i + 1;
        }
        return filho;
    }

    

    

    public static void ler(int num){
        arq.openRead("players.csv");
        int i = 0;
        String str = "";
        while(i < num + 1){
            comp++;
            arq.readLine();
            i++;
        }
        str = arq.readLine();
        //myIo.println(str + " " + num);
        str += " ";
        String[] parts = str.split(",");
        for (int k = 0; k < parts.length; k++) {
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
        lerTamanho();
        lerNomes();
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
        arq.openWriteClose("matrícula_heapsort.txt", conteudo);
    }
}