class q05{
    //public static int comp = 0;
    public static int[] ids = new int[500];
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
            temp = arq.readLine();
            String[] parts = temp.split(",");
            nomes[i] = parts[1];
            i++;
        }
        arq.close();
    }

    public static int compStr(int prim, int sec){
        int i = 0;
        int result = 0;
        String a = nomes[prim + 1];
        String b = nomes[sec + 1];

        //myIo.println(a + b);

        if(a != null && b != null){
            result = a.compareToIgnoreCase(b); 
        }
        return result;
    } 

    public static void ordenar(int k){
        for (int i = 0; i < k - 1 ; i++) {
            int menor = i;
            for (int j = (i + 1); j < k; j++){
                if (compStr(ids[menor], ids[j]) > 0){
                     menor = j;
                }  
            }
            swap(menor, i);
        }
    }

    

    public static void ler(int num){
        arq.openRead("/tmp/players.csv");
        int i = 0;
        String str = "";
        while(i < num + 1){
            arq.readLine();
            i++;
        }
        str = arq.readLine();
        //myIo.println(str + " " + num);
        str += " ";
        String[] parts = str.split(",");
        for (int k = 0; k < parts.length; k++) {
            if (parts[k].isEmpty()) {
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
        System.out.println("[" + id + " ## " + nome + " ## " + altura + " ## " + peso + " ## " + anoNascimento + " ## " + universidade + " ## " + cidadeNascimento + " ## " + estadoNascimento.trim() + "]");
        arq.close();
    }



    public static void main(String[] args){
        String id = "";
        String nome = "";
        int i = 0;
        int j = 0;
        int teste = 0;
        double inicio, fim;

        
        do{
            id = myIo.readLine();
            if (!id.equalsIgnoreCase("FIM")){
                ids[i] = Integer.parseInt(id);
                i++;
            }
        } while (!id.equalsIgnoreCase("FIM"));
        lerNomes();
        ordenar(i);

        /*for (int k = 0; k < ids.length; k++){
            if(ids[k]!=0){
                myIo.println(ids[k]);
            }
            
        }*/

        inicio = System.currentTimeMillis();
        for (j = 0; j < i; j++){
            teste = ids[j];
            if(teste != 0){
              ler(teste);
            }

        }
        fim = System.currentTimeMillis();
        
        //String tempo = (fim-inicio)/1000 + "\t";
        //String conteudo = "816479\t" + tempo + comp;
        //arq.openWriteClose("matrícula_sequencial.txt", conteudo);
    }
}