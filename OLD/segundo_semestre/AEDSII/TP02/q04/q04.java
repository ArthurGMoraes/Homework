import java.util.*;

class q04{
    public static int comp = 0;
    public static int n = 0;
    public static int[] ids = new int[80];
    public static Arq arq = new Arq();
    public static MyIO myIo = new MyIO();

    public static String readArq(int x){
        String str = "";
        for (int i = 0; i < x + 1; i++){
            comp++;
            arq.readLine();
        }   
        str = arq.readLine();
        return str;
    }

    public static int getId(String nome){
        String str = "";
        int id = 0;
        arq.openRead("players.csv");
        //myIo.println("ok");
        do{
            
            if(!str.equals(nome)){
                if (nome.equals("Sarunas Marciulionis")){
                    nome = "Sarunas Marciulionis*";
                }
                str = arq.readLine();
                String[] parts = str.split(",");
                str = parts[1];
                
                
                if (!parts[0].equalsIgnoreCase("id")){
                    id = Integer.parseInt(parts[0]);  
                }
            } 
            
        } while (!str.equalsIgnoreCase(nome));
        //myIo.println(str);
        //myIo.println(str + " " + nome);
        arq.close();
        return id;

    }

    public static boolean pesquisar(String nome){
        boolean resp = false;
        String str = "";
        int dir = n, esq = 0, meio;

        while (esq <= dir){
            arq.openRead("players.csv");
            meio = (esq + dir) / 2;
            
            str = readArq(ids[meio]);
            String[] parts = str.split(",");
            //myIo.println(dir + " " + esq + " " + meio + " " + Integer.parseInt(parts[0]) + " " + ids[meio]);

            if(parts[1].equals(nome)){
                resp = true;
                esq = dir + 1;
            } else if (getId(nome) > ids[meio]) {
                esq = meio + 1;
            } else {
                dir = meio - 1;
            }
            arq.close();
        }
        return resp;
    }


    public static void ordenar(){
        quicksort(0, n-1);
    }

    public static void swap(int i, int j) {
      int temp = ids[i];
      ids[i] = ids[j];
      ids[j] = temp;
   }

    public static void quicksort(int esq, int dir) {
        int i = esq, j = dir;
        int pivo = ids[(dir+esq)/2];
        while (i <= j) {
            while (ids[i] < pivo) i++;
            while (ids[j] > pivo) j--;
            if (i <= j) {
                swap(i, j);
                i++;
                j--;
            }
        }
        if (esq < j)  quicksort(esq, j);
        if (i < dir)  quicksort(i, dir);
    }


    public static void main(String[] args){
        String id = "";
        String nome = "";
        int i = 0;
        int j = 0;
        double inicio, fim;

        
        do{
            id = myIo.readLine();
            if (!id.equalsIgnoreCase("FIM")){
                ids[i] = Integer.parseInt(id);
                i++;
                n++;
            }
        } while (!id.equalsIgnoreCase("FIM"));

        /*for(int k = 0; k < n; k++){
            myIo.print(ids[k] + " ");
        }*/
        //myIo.println(" ");
        ordenar();
       
        /*for(int l = 0; l < n; l++){
            myIo.print(ids[l] + " ");
        }*/

        //inicio = System.currentTimeMillis();
        do{
            nome = myIo.readLine();
            //myIo.println("nome: " + nome);
            if (!nome.equalsIgnoreCase("FIM")){
                myIo.println(pesquisar(nome)?"SIM":"NAO");
            }
        } while (!nome.equalsIgnoreCase("FIM"));
        //fim = System.currentTimeMillis();
        
        //String tempo = (fim-inicio)/1000 + "\t";
        //String conteudo = "816479\t" + tempo + comp;
        //arq.openWriteClose("matrícula_sequencial.txt", conteudo);
    }
}