import java.util.*;

class q08{
    public static int comp = 0;
    
    public static class TabelaHash{
        String tabela[];
        int tamanho,areaHash,tamReserva,reserva;

        public TabelaHash(){
            tamanho = 25;
            tabela = new String[25];

            for (int i = 0; i < 25; i++){
                tabela[i] = null;
            }
        }

        public int hash(int altura){
            return altura%25;
        }

        public int rehash(int altura){
            return (altura+1)%25;
        }

        public void inserir(String nome, int altura){
            int pos = hash(altura);
            if (tabela[pos] == null) {
                comp++;
                tabela[pos] = nome;
            } else if (tabela[rehash(altura)] == null) {
                comp++;
                tabela[rehash(altura)] = nome;
            }
        }

        public boolean pesquisar(String nome, int altura) {
            boolean resp = false;
            int pos = hash(altura);
            if (tabela[pos] == null){
                comp++;
                resp = false;
            } else if (tabela[pos].equals(nome)) {
                comp++;
                resp = true;
            } else if (tabela[rehash(altura)] == null) {
                comp++;
                resp = false;
            } else if (tabela[rehash(altura)].equals(nome)){
                comp++;
                resp = true;
            }
            return resp;
        }
    }


    public static String[] ler(int id){
            MyIO myIo = new MyIO();
            Arq arq = new Arq();
            int i = 0;
            String str = "";
            arq.openRead("/tmp/players.csv");
            while(i < id + 1){
                arq.readLine();
                i++;
            }
            str = arq.readLine();
            String[] parts = str.split(",");
            arq.close();

            return parts;
    }

    public static int getAltura(String nome){
            MyIO myIo = new MyIO();
            Arq arq = new Arq();
            int i = 0;
            String str = "";
            String[] parts;
            arq.openRead("/tmp/players.csv");
            do {
                str = arq.readLine();
                parts = str.split(",");
            } while(!parts[1].equals(nome) && Arq.hasNext());
            
            arq.close();

            return Integer.parseInt(parts[2]);
    }

    public static void main(String[] args){
        String entrada = "";
        TabelaHash tabHash = new TabelaHash();
        String parts[];
        String str = "";
        double inicio, fim;

        inicio = System.currentTimeMillis();

        while (!entrada.equals("FIM")){
            entrada = MyIO.readString();
            if(!entrada.equals("FIM")){
                parts = ler(Integer.parseInt(entrada));
                tabHash.inserir(parts[1], Integer.parseInt(parts[2]));
            } 
        }
        do{
            entrada = MyIO.readLine();
            if(!entrada.equals("FIM")){
                MyIO.println(entrada + " " + (tabHash.pesquisar(entrada, getAltura(entrada))?"SIM":"NAO"));
            }
        } while (!entrada.equals("FIM"));

        fim = System.currentTimeMillis();

        String tempo = (fim-inicio)/1000 + "\t";
        String conteudo = "816479\t" + tempo + comp;
        Arq.openWriteClose("816479_hashRehash.txt", conteudo);
    }
}