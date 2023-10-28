import java.util.*;

class q01{
    public static class Jogador{
        private int id;
        private String nome;
        private int altura;
        private int peso;
        private String universidade;
        private int anoNascimento;
        private String cidadeNascimento;
        private String estadoNascimento;
        private Jogador prox;

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

    public static class Lista{
        private Jogador inicio;
        private int n;

        public Lista(){
            inicio = null;
            n = 0;
        }

        public void inserirInicio(Jogador jogador){
            if (inicio == null){
                inicio = jogador;
                n++;
            } else {
                jogador.prox = inicio;
                inicio = jogador;
                n++;
            }
        }

        public void inserir(Jogador jogador, int posicao){
            Jogador j = inicio;
            if(inicio == null){
                inicio = jogador;
                n++;
            } else if (posicao <= n){
                for (int i = 0; i < posicao-1; i++){
                    j = j.prox;
                }
                Jogador tmp = j.prox;
                //System.out.println(tmp.nome);
                jogador.prox = tmp;
                j.prox = jogador;
                n++;
            }
        }

        public void inserirFim(Jogador jogador){
            if(inicio == null){
                inicio = jogador;
                n++;
            } else {
                Jogador i;
                for (i = inicio; i.prox != null; i = i.prox);
                i.prox = jogador;
                n++;
            }
        }

        public Jogador removerInicio(){
            Jogador removido = null;
            if (inicio != null){
                removido = inicio;
                inicio = inicio.prox;
                n--;
            }
            return removido;
        }

        public Jogador remover(int pos){
            Jogador removido = null;
            Jogador j = inicio;
            if (inicio != null){
                for (int i = 0; i < pos - 1; i++){
                    j = j.prox;
                }
                Jogador tmp = j.prox.prox;
                removido = j.prox;
                j.prox = tmp;
                n--;
            }
            return removido;
        }

        public Jogador removerFim(){
            Jogador removido = null;
            Jogador i;
            if (inicio != null){
                for (i = inicio; i.prox.prox != null; i = i.prox);
                removido = i.prox;
                i.prox = null;
                n--;
            }
            return removido;
        }

        public void imprimir(){
            int j = 0;
            for(Jogador i = inicio; i != null; i = i.prox, j++){
                System.out.println("[" + j + "]" + " ## " + i.nome + " ## " + i.altura + " ## " + i.peso + " ## " + i.anoNascimento + " ## " + i.universidade + " ## " + i.cidadeNascimento + " ## " + i.estadoNascimento.trim() + " ##");
            }
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
        Lista lista = new Lista();

        while (!id.equals("FIM")){
            id = myIo.readString();
            if (!id.equals("FIM")){
                Jogador jogador = new Jogador(Integer.parseInt(id));
                jogador.ler();
                lista.inserirFim(jogador);
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
                lista.inserirInicio(jogador);
            } else if(action.equals("I*")){
                lista.inserir(jogador, pos);
            } else if (action.equals("IF")){
                lista.inserirFim(jogador);
            } else if (action.equals("RI")){
                myIo.println("(R) "+lista.removerInicio().nome);
            } else if (action.equals("R*")){
                pos = myIo.readInt();
                myIo.println("(R) "+lista.remover(pos).nome);
            } else if (action.equals("RF")){
                myIo.println("(R) "+lista.removerFim().nome);
            }
        }
        lista.imprimir();
    }
}