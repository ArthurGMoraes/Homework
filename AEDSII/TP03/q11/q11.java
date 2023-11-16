import java.util.*;

class q11{
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
        private Jogador ant;

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
        private Jogador fim;
        private int n;

        public Lista(){
            inicio = null;
            n = 0;
        }

        public void inserirFim(Jogador jogador){
            if(inicio == null){
                inicio = jogador;
                fim = jogador;
                jogador.prox = jogador.ant = null;
                n++;
            } else {
                fim.prox = jogador;
                jogador.prox = null;
                jogador.ant = fim;
                fim = jogador;
                n++;
            }
        }

        public void quicksort(){
            quicksort(inicio, fim);
        }

        public static int comparar(Jogador a, Jogador b){
            int result = a.estadoNascimento.compareTo(b.estadoNascimento);
            if (result == 0){
                result = a.nome.compareTo(b.nome);      
            }
            return result;
        }

        public static Jogador partition(Jogador left, Jogador right)
        {
            Jogador pivot = right;
            Jogador i = left.ant;
            for(Jogador ptr=left; ptr!=right; ptr=ptr.prox)
            {
                if(comparar(ptr,pivot) < 0){
                    i = (i==null?left:i.prox);
                    int tmpId = i.id;
                    String tmpNome = i.nome;
                    int tmpAltura = i.altura;
                    int tmpPeso = i.peso;
                    String tmpUniversidade = i.universidade;
                    int tmpAnoNascimento = i.anoNascimento;
                    String tmpCidadeNascimento = i.cidadeNascimento;
                    String tmpEstadoNascimento = i.estadoNascimento;
                    i.id = ptr.id;
                    i.nome = ptr.nome;
                    i.altura = ptr.altura;
                    i.peso = ptr.peso;
                    i.universidade = ptr.universidade;
                    i.anoNascimento = ptr.anoNascimento;
                    i.cidadeNascimento = ptr.cidadeNascimento;
                    i.estadoNascimento = ptr.estadoNascimento;
                    ptr.id = tmpId;
                    ptr.nome = tmpNome;
                    ptr.altura = tmpAltura;
                    ptr.peso = tmpPeso;
                    ptr.universidade = tmpUniversidade;
                    ptr.anoNascimento = tmpAnoNascimento;
                    ptr.cidadeNascimento = tmpCidadeNascimento;
                    ptr.estadoNascimento = tmpEstadoNascimento;
                }
            }
            i = (i==null?left:i.prox);
            int tempId = i.id;
            String tempNome = i.nome;
            int tempAltura = i.altura;
            int tempPeso = i.peso;
            String tempUniversidade = i.universidade;
            int tempAnoNascimento = i.anoNascimento;
            String tempCidadeNascimento = i.cidadeNascimento;
            String tempEstadoNascimento = i.estadoNascimento;
            i.id = pivot.id;
            i.nome = pivot.nome;
            i.altura = pivot.altura;
            i.peso = pivot.peso;
            i.universidade = pivot.universidade;
            i.anoNascimento = pivot.anoNascimento;
            i.cidadeNascimento = pivot.cidadeNascimento;
            i.estadoNascimento = pivot.estadoNascimento;
            pivot.id = tempId;
            pivot.nome = tempNome;
            pivot.altura = tempAltura;
            pivot.peso = tempPeso;
            pivot.universidade = tempUniversidade;
            pivot.anoNascimento = tempAnoNascimento;
            pivot.cidadeNascimento = tempCidadeNascimento;
            pivot.estadoNascimento = tempEstadoNascimento;
            return i;
        }

        public static void quicksort(Jogador left, Jogador right)
        {
            if(right!=null && left!=right && left!=right.prox)
            {
                Jogador p = partition(left,right);
                quicksort(left,p.ant);
                quicksort(p.prox,right);
            }
        }

        public void imprimir(){
            int j = 0;
            for(Jogador i = inicio; i != null; i = i.prox, j++){
                i.imprimir();
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
        lista.quicksort();
        lista.imprimir();
    }
}