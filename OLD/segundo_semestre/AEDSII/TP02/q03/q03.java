import java.util.*;

class q03{
    public static int comp = 0;
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

    public static boolean pesquisar(String nome){
        boolean resp = false;
        String str = "";
        
        for(int i = 0; i < ids.length; i++){
            comp++;
            arq.openRead("/tmp/players.csv");
            
            str = readArq(ids[i]);

            String[] parts = str.split(",");

            //myIo.println(parts[1] + nome);
            if (parts[1].equals(nome)){
                return true;
            }
            comp++;
            arq.close();
        }

        return resp;
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
            }
        } while (!id.equalsIgnoreCase("FIM"));

        inicio = System.currentTimeMillis();
        do{
            nome = myIo.readLine();
            if (!nome.equalsIgnoreCase("FIM")){
                myIo.println(pesquisar(nome)?"SIM":"NAO");
            }
        } while (!nome.equalsIgnoreCase("FIM"));
        fim = System.currentTimeMillis();
        
        String tempo = (fim-inicio)/1000 + "\t";
        String conteudo = "816479\t" + tempo + comp;
        arq.openWriteClose("816479_sequencial.txt", conteudo);
    }
}