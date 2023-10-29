import java.util.*;

class q06{
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
            prox = null;
        }
    }

    public static class Pilha{
        private Jogador topo;

        public Pilha(){
            topo = null;
        }

        public void inserir(Jogador jogador){
            if (topo == null){
                topo = jogador;
            } else {
                jogador.prox = topo;
                topo = jogador;
            }
        }

        public Jogador remover(){
            Jogador removido = topo;
            topo = topo.prox;
            return removido;
        }

        public void imprimir(){
            int j = 0;
            String array[] = new String[500];
            for (Jogador i = topo; i != null; i = i.prox, j++){
                array[j] = (" ## " + i.nome + " ## " + i.altura + " ## " + i.peso + " ## " + i.anoNascimento + " ## " + i.universidade + " ## " + i.cidadeNascimento + " ## " + i.estadoNascimento.trim() + " ##");
            }
            for (int i = j-1, k = 0; i >= 0; i--){
                System.out.println("["+k+"]" + array[i]);
                k++;
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
        Pilha pilha = new Pilha();

        while (!id.equals("FIM")){
            id = myIo.readString();
            if (!id.equals("FIM")){
                Jogador jogador = new Jogador(Integer.parseInt(id));
                jogador.ler();
                pilha.inserir(jogador);
            }
        }
        
        quant = myIo.readInt();
        for(i = 0; i < quant; i++){
            //lista.imprimir();
            Jogador jogador = null;
            action = myIo.readString();
            //myIo.println(action);
            if (action.equals("I")){
                id2 = myIo.readInt();
                jogador = new Jogador(id2);
                jogador.ler();
                pilha.inserir(jogador);
            } else if (action.equals("R")){
                myIo.println("(R) " + pilha.remover().nome);
            }
        }
        pilha.imprimir();
    }
}