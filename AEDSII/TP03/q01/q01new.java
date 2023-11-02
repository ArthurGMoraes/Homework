import java.util.*;

class q01new{
    public static class Jogador{
        private int id;
        private String nome;
        private int altura;
        private int peso;
        private String universidade;
        private int anoNascimento;
        private String cidadeNascimento;
        private String estadoNascimento;

        public Jogador (int id){
            this.id = id;
        }

        public Jogador (int id, String nome, int altura, int peso, String universidade, int anoNascimento, String cidadeNascimento, String estadoNascimento){
            this.id = id;
            this.nome = nome;
            this.altura = altura;
            this.peso = peso;
            this.universidade = universidade;
            this.anoNascimento = anoNascimento;
            this.cidadeNascimento = cidadeNascimento;
            this.estadoNascimento = estadoNascimento;
        }

        public void imprimir(){
            System.out.println("[" + id + " ## " + nome + " ## " + altura + " ## " + peso + " ## " + anoNascimento + " ## " + universidade + " ## " + cidadeNascimento + " ## " + estadoNascimento.trim() + "]");
        }

        public void ler(){
            MyIO myIo = new MyIO();
            Arq arq = new Arq();
            int i = 0;
            String str = "";
            arq.openRead("/tmp/players.csv");
            while(i < this.id + 1){
                arq.readLine();
                i++;
            }
            str = arq.readLine();
            str += " ";
            String[] parts = str.split(",");
            for (int k = 0; k < parts.length; k++) {
                if (parts[k].isEmpty() || parts[k].equals(" ")) {
                    parts[k] = "nao informado";
                }
            }
            arq.close();
            setInfos(parts[1], Integer.parseInt(parts[2]), Integer.parseInt(parts[3]), parts[4], Integer.parseInt(parts[5]), parts[6], parts[7]);
        }

        public void setInfos(String nome, int altura, int peso, String universidade, int anoNascimento, String cidadeNascimento, String estadoNascimento){
            this.nome = nome;
            this.altura = altura;
            this.peso = peso;
            this.universidade = universidade;
            this.anoNascimento = anoNascimento;
            this.cidadeNascimento = cidadeNascimento;
            this.estadoNascimento = estadoNascimento;
        }
    }

    public static Jogador[] l = new Jogador[250];
    public static int n = 0;

        public static void inserirInicio(Jogador c){
            if (n < 250){
                for (int i = n; i > 0; i--) {
                        l[i] = l[i - 1];
                }
                l[0] = c;
                n++;
            }
        }

        public static void inserir(Jogador c, int pos){
            if (n < 250 && pos >= 0 && pos <= n){
                for (int i = n; i > pos; i--){
                    l[i] = l[i - 1];
                }
                l[pos] = c;
                n++;
            }
        }

        public static void inserirFim(Jogador c){
            if (n < 250){
                l[n] = c;
                n++;
            }
        }

        public static Jogador removerInicio(){
            Jogador resp = null;
            if (n != 0){
                resp = l[0];
                n--;
                for(int i = 0; i < n; i++){
                    l[i] = l[i+1];
                }
            }
            return resp;
        }

        public static Jogador remover(int pos){
            Jogador resp = null;
            if (n != 0 && pos >= 0 && pos < 250){
                resp = l[pos];
                n--;
                for(int i = pos; i < n; i++){
                    l[i] = l[i+1];
                }
            }
            return resp;
        }

        public static Jogador removerFim(){
            if (n != 0){
                return l[--n];
            }
            return null;
        }

        public static void imprimir(){
            for(int i = 0; i < n; i++){
                System.out.println("[" + i + "]" + " ## " + l[i].nome + " ## " + l[i].altura + " ## " + l[i].peso + " ## " + l[i].anoNascimento + " ## " + l[i].universidade + " ## " + l[i].cidadeNascimento + " ## " + l[i].estadoNascimento.trim() + " ##");
            }
        }
    

    

    public static void main(String[] args){
        MyIO myIo = new MyIO();
        Arq arq = new Arq();
        String id = "";
        String action = "";
        int i = 0;
        int id2 = 0;
        int quant = 0;
        int pos = 0;
    

        while (!id.equals("FIM")){
            id = myIo.readString();
            if (!id.equals("FIM")){
                Jogador jogador = new Jogador(Integer.parseInt(id));
                jogador.ler();
                inserirFim(jogador);
            }
        }
        
        quant = myIo.readInt();
        for(i = 0; i < quant; i++){
            //lista.imprimir();
            Jogador jogador = null;
            action = myIo.readString();
            //myIo.println(action);
            if(!(action.equals("RI")) && !(action.equals("RF")) && !(action.equals("R*")) && !(action.equals("I*")) ){
                id2 = myIo.readInt();
                jogador = new Jogador(id2);
                jogador.ler();
            } else if (action.equals("I*")){
                pos = myIo.readInt();
                id2 = myIo.readInt();
                jogador = new Jogador(id2);
                jogador.ler();
            }
            if(action.equals("II")){
                inserirInicio(jogador);
            } else if(action.equals("I*")){
                inserir(jogador, pos);
            } else if (action.equals("IF")){
                inserirFim(jogador);
            } else if (action.equals("RI")){
                myIo.println("(R) "+removerInicio().nome);
            } else if (action.equals("R*")){
                pos = myIo.readInt();
                myIo.println("(R) "+remover(pos).nome);
            } else if (action.equals("RF")){
                myIo.println("(R) "+removerFim().nome);
            }
        }
        imprimir();
    }
}