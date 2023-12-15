import java.util.*;

class q06{
    public static int comp = 0;
    public static class No{
        public char elemento;
        public final int tamanho = 255;
        public No[] prox;
        public boolean folha;
   
        public No (){
            this(' ');
        }

        public No (char elemento){
            this.elemento = elemento;
            prox = new No [tamanho];
            for (int i = 0; i < tamanho; i++) prox[i] = null;
            folha = false;
        }

        public static int hash (char x){
            return (int)x;
        }
    }

    public static class Arvore{
        private No raiz;

        public Arvore(){
            raiz = new No();
        }
        public void inserir(String s){
            inserir(s, raiz, 0);
        }

        private void inserir(String s, No no, int i){
            if(no.prox[s.charAt(i)] == null){
                comp++;
                no.prox[s.charAt(i)] = new No(s.charAt(i));
                if(i == s.length() - 1){
                    comp++;
                    no.prox[s.charAt(i)].folha = true;
                }else{
                    inserir(s, no.prox[s.charAt(i)], i + 1);
                }
            } else if (no.prox[s.charAt(i)].folha == false && i < s.length() - 1){
                comp++;
                inserir(s, no.prox[s.charAt(i)], i + 1);
            } 
        }   

        public void mostrar(){
            mostrar("", raiz);
        }

        public void mostrar(String s, No no) {
            if(no.folha == true){
                System.out.println("Palavra: " + (s + no.elemento));
            } else {
                for(int i = 0; i < no.prox.length; i++){
                    if(no.prox[i] != null){
                        //System.out.println("ESTOU EM (" + no.elemento + ") E VOU PARA (" + no.prox[i].elemento + ")");
                        mostrar(s + no.elemento, no.prox[i]);
                    }
                }
            }
        }

        public void merge(Arvore arvore1, Arvore arvore2) {
            // Chama uma função auxiliar para fazer o merge a partir da raiz das duas árvores
            mergeRecursivo("",arvore1.raiz);
            mergeRecursivo("",arvore2.raiz);
        }

        private void mergeRecursivo(String s, No atual) {
            if (atual != null) {
                if (atual.folha) {
                    comp++;
                    // Se o nó atual é uma folha, insere na árvore resultado
                    inserir((s + atual.elemento).trim());
                } else {
                    for (int i = 0; i < atual.prox.length; i++) {
                        if (atual.prox[i] != null) {
                            comp++;
                            // Continua o merge recursivamente
                            mergeRecursivo(s + atual.elemento, atual.prox[i]);
                        }
                    }
                } 
            }
        }

        public boolean pesquisar(String s) {
            return pesquisar(s, raiz, 0);
        }

        public boolean pesquisar(String s, No no, int i) {
            boolean resp = false;
            if(no.prox[s.charAt(i)] == null){
                comp++;
                resp = false;
            } else if(i == s.length() - 1){
                comp++;
                resp = (no.prox[s.charAt(i)].folha == true);
            } else if(i < s.length() - 1 ){
                comp++;
                resp = pesquisar(s, no.prox[s.charAt(i)], i + 1);
            } 
            return resp;
        }

    }

    public static String ler(int id){
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
            if (parts[1] == null){
                parts[1] = "nao informado";
            }
            str = parts[1];
            return str;
    }

    public static void main(String[] args){
        String entrada = "";
        Arvore arv1 = new Arvore();
        Arvore arv2 = new Arvore();
        Arvore arv3 = new Arvore();
        String str = "";
        double inicio, fim;

        inicio = System.currentTimeMillis();

        while (!entrada.equals("FIM")){
            entrada = MyIO.readString();
            if(!entrada.equals("FIM")){
                str = ler(Integer.parseInt(entrada));
                MyIO.println(entrada + "\t" + str);
                arv1.inserir(str);
            } 
        }

        do {
            entrada = MyIO.readString();
            if(!entrada.equals("FIM")){
                str = ler(Integer.parseInt(entrada));
                MyIO.println(entrada + "\t" + str);
                arv2.inserir(str);
            }    
        } while (!entrada.equals("FIM"));

        arv3.merge(arv1, arv2);

        //arv3.mostrar();

        do {
            entrada = MyIO.readLine();
            if(!entrada.equals("FIM")){
                MyIO.println(entrada + " " + (arv3.pesquisar(entrada)?"SIM":"NAO"));
            }    
        } while (!entrada.equals("FIM"));

        fim = System.currentTimeMillis();

        String tempo = (fim-inicio)/1000 + "\t";
        String conteudo = "816479\t" + tempo + comp;
        Arq.openWriteClose("816479_arvoreTrie.txt", conteudo);
    }
}