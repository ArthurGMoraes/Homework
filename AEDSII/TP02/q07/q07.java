class q07{
    public static int comp = 0;
    public static int trocas = 0;
    public static int[] ids = new int[500];
    public static int[] anos = new int[4000];
    public static String[] nomes = new String[4000];
    public static Arq arq = new Arq();
    public static MyIO myIo = new MyIO();

    public static void swap(int i, int j) {
        int temp = ids[i];
        ids[i] = ids[j];
        ids[j] = temp;
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

    public static void lerAno(){
        arq.openRead("/tmp/players.csv");
        int i = 0;
        String temp;
        arq.readLine();  // pular primeira linha
        while(arq.hasNext() == true){
            comp++;
            temp = arq.readLine();
            String[] parts = temp.split(",");
            anos[i] = Integer.parseInt(parts[5]);
            i++;
        }
        arq.close();
    }

    public static int compAno(int prim, int sec){
        int i = 0;
        int result = -1;
        int a = anos[prim];
        int b = anos[sec];
        String c = nomes[prim + 1];;
        String d = nomes[sec + 1];;

        //myIo.println(a + " " + b);

        if(a != 0 && b != 0){
            comp++;
            if(a>b){
                result = 1;
            } else if (a == b){
                result = c.compareToIgnoreCase(d);
            }
        }
        return result;
    } 




    public static void ordenar(int k) {
		for (int i = 1; i < k + 1; i++) {
			int tmp = ids[i];
            int j = i - 1;

         while ((j >= 0) && (compAno(ids[j], tmp) > 0)) {
            ids[j + 1] = ids[j];
            trocas++;
            j--;
         }
         ids[j + 1] = tmp; trocas++;
         //myIo.println(j+ 1 + " " + anos[j+1]);
      }
	}

    

    public static void ler(int num){
        arq.openRead("/tmp/players.csv");
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
        lerAno();
        lerNomes();
        ordenar(i);

        /*for (int k = 0; k < ids.length; k++){
            if(ids[k]!=0){
                myIo.println(ids[k]);
            }
            
        }*/

        
        for (j = 0; j < i+1; j++){
            teste = ids[j];
            if(teste != 0){    // array preenchido com 0s
              ler(teste);
              comp++;
            }

        }
        fim = System.currentTimeMillis();
        
        String tempo = (fim-inicio)/1000 + "";
        String conteudo = "816479\t" + comp + "\t" + trocas + "\t" + tempo;
        arq.openWriteClose("matrícula_insercao.txt", conteudo);
    }
}