import java.util.*;

class q07{
    public static int comp = 0;
    
    public static class TabelaHash{
        String tabela[];
        int tamanho,areaHash,tamReserva,reserva;

        public TabelaHash(){
            tamanho = 30;
            areaHash = 21;
            tamReserva = 9;
            reserva = 0;
            tabela = new String[30];

            for (int i = 0; i < 21; i++){
                tabela[i] = null;
            }
        }

        public int hash(String nome){
            int tam = nome.length();
            int hash = 0;

            for (int x = 0; x < tam; x++){
                hash += nome.charAt(x) * (x+1);
                MyIO.print(nome.charAt(x));
            }
            MyIO.println(" " + hash%21);
            return hash%21;
        }

        public void inserir(String nome){
            if (nome != null) {
                comp++;
                int pos = hash(nome);
                if (tabela[pos] == null) {
                    comp++;
                    tabela[pos] = nome;
                } else if (reserva < tamReserva) {
                    comp++;
                    tabela[areaHash + reserva] = nome;
                    reserva++;
                }
            }
        }

        public boolean pesquisar(String nome) {
            boolean resp = false;
            int pos = hash(nome);
            if (tabela[pos] == null){
                comp++;
                resp = false;
            } else if (tabela[pos].equals(nome)) {
                comp++;
                resp = true;
            } else {
                for (int i = 0; i < reserva; i++) {
                    if (tabela[areaHash + i].equals(nome)) {
                        resp = true;
                        i = reserva;
                    }
                }
            }
            return resp;
        }
    }


    public static String ler(int id){
            MyIO myIo = new MyIO();
            Arq arq = new Arq();
            int i = 0;
            String str = "";
            arq.openRead("players.csv");
            while(i < id + 1){
                arq.readLine();
                i++;
            }
            str = arq.readLine();
            String[] parts = str.split(",");
            arq.close();
            if (parts[1] == null){
                parts[1] = "nao informado";
            }
            str = parts[1];
            return str;
    }

    public static void main(String[] args){
        String entrada = "";
        TabelaHash tabHash = new TabelaHash();
        String str = "";
        double inicio, fim;

        inicio = System.currentTimeMillis();

        while (!entrada.equals("FIM")){
            entrada = MyIO.readString();
            if(!entrada.equals("FIM")){
                str = ler(Integer.parseInt(entrada));
                tabHash.inserir(str);
            } 
        }
        do{
            entrada = MyIO.readLine();
            if(!entrada.equals("FIM")){
                MyIO.println(entrada + " " + (tabHash.pesquisar(entrada)?"SIM":"NAO"));
            }
        } while (!entrada.equals("FIM"));

        fim = System.currentTimeMillis();

        String tempo = (fim-inicio)/1000 + "\t";
        String conteudo = "816479\t" + tempo + comp;
        Arq.openWriteClose("816479_hashReserva.txt", conteudo);
    }
}