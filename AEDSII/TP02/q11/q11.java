class q11{
    public static int comp = 0;
    public static int trocas = 0;
    public static int[] ids = new int[500];
    public static int[] tamanhosT = new int[4000];
    public static int[] tamanhos = new int[500];
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
            tamanhosT[i] = Integer.parseInt(parts[2]);
            i++;
        }
        arq.close();
    }

    public static int compTamanhos(int prim, int sec, int id1, int id2){
        int i = 0;
        int result = -1;
        String c = nomes[id1 + 1];;
        String d = nomes[id2 + 1];;

        //myIo.println(a + " " + b);

        if(prim != 0 && sec != 0){
            comp++;
            if(prim>sec){
                result = 1;
            } else if (prim == sec){
                result = (c.compareTo(d));
            }
        }
        return result;
    } 

    public static void getArrayTam(int k){
        for (int i = 0; i < k; i++){
            tamanhos[i] = tamanhosT[ids[i]];
        }
    }



    public static void ordenar(int k) {
      //Array para contar o numero de ocorrencias de cada elemento
      getArrayTam(k);
      int[] count = new int[getMaior(k) + 1];
      int[] ordenado = new int[k];
      int[] ordenado2 = new int[k];

      //Inicializar cada posicao do array de contagem 
		for (int i = 0; i < count.length; count[i] = 0, i++);

      //Agora, o count[i] contem o numero de elemento iguais a i
      for (int i = 0; i < k; count[tamanhos[i]]++, i++);

      //Agora, o count[i] contem o numero de elemento menores ou iguais a i
      for(int i = 1; i < count.length; count[i] += count[i-1], i++);

      //Ordenando
      for(int i = k-1; i >= 0; ordenado[count[tamanhos[i]]-1] = tamanhos[i], ordenado2[count[tamanhos[i]]-1] = ids[i], count[tamanhos[i]]--, i--, trocas += 2);

      //Copiando para o array original
      for(int i = 0; i < k; tamanhos[i] = ordenado[i], ids[i] = ordenado2[i], i++);
   }

	public static int getMaior(int k) {
	   int maior = tamanhos[0];
       int j = 0;

		for (int i = 0; i < k; i++) {
         if(maior < tamanhos[i]){
            maior = tamanhos[i];
         }
		}
	   return maior;	
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
        //getArrayTam(i);
        ordenar(i);

        for(j = 0; j < i; j++){
            //myIo.println(tamanhos[j]);
        }

        
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
        arq.openWriteClose("matrícula_countingsort.txt", conteudo);
    }
}