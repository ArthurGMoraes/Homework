class q05{
    //public static int comp = 0;
    public static int[] ids = new int[463];
    public static Arq arq = new Arq();
    public static MyIO myIo = new MyIO();

    public static void swap(int i, int j) {
        int temp = ids[i];
        ids[i] = ids[j];
        ids[j] = temp;
    }

    public static void ordenar(){
        for (int i = 0; i < ids.length - 1; i++) {
            int menor = i;
            for (int j = (i + 1); j < ids.length; j++){
                if (ids[menor] > ids[j]){
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
        myIo.println(str + " " + num);
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
                myIo.println(ids[i]);
                i++;
            }
        } while (!id.equalsIgnoreCase("FIM"));

        myIo.println("");

        ordenar();

        for (int k = 0; k < ids.length; k++){
            myIo.println(ids[k]);
        }

        /*inicio = System.currentTimeMillis();
        for (j = 0; j < ids.length; j++){
            teste = ids[j];
            ler(teste);
        }*/
        fim = System.currentTimeMillis();
        
        //String tempo = (fim-inicio)/1000 + "\t";
        //String conteudo = "816479\t" + tempo + comp;
        //arq.openWriteClose("matrícula_sequencial.txt", conteudo);
    }
}