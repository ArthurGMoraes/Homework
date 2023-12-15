import java.util.*;

class q09{
    public static class Celula{
        private int val;
        private Jogador inf,sup,dir,esq;

        public Celula (){
            this(0);
        }

        public Celula (int valor){
            this(valor, null, null, null);
        }

        public Celula(valor, inf, esq, sup, dir){
            val = valor;
            this.esq = esq;
            this.dir = dir;
            this.sup = sup;
            this.inf = inf;
        }
       
    }

    public static class Matriz{
        private Jogador inicio;
        private int linha, coluna;

        public Matriz(){
            inicio = null;
        }

        public Matriz(int linha, int coluna){
            this.linha = linha;
            this.coluna = coluna;
        }

        public void ler(){
            MyIO myIo = new MyIO();
            int valor;
            Celula tmp = inicio;
            
    }

    

    public static void main(String[] args){
        MyIO myIo = new MyIO();
        
        
    }
}