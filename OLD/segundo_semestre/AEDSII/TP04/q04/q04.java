import java.util.*;

class q04{
    public static int comp = 0;
    public static class No{
        private String nome;
        private boolean cor;
        private No dir;
        private No esq;

        public No(String nome) {
            this(nome, false, null, null);
        }

        public No(String nome, boolean cor) {
            this(nome, cor, null, null);
        }

        public No(String nome, boolean cor, No esq, No dir) {
            this.cor = cor;
            this.nome = nome;
            this.esq = esq;
            this.dir = dir;
        }
    }

    public static class Arvore{
        private No raiz;

        public Arvore(){
            raiz = null;
        }

        public void inserir(String nome) {
            // Se a arvore estiver vazia
            if (raiz == null) {
            raiz = new No(nome);
            comp++;
            // Senao, se a arvore tiver um nome
            } else if (raiz.esq == null && raiz.dir == null) {
                comp++;
                if (nome.compareTo(raiz.nome) < 0) {   
                    comp++;  
                    raiz.esq = new No(nome);
                } else {
                    raiz.dir = new No(nome);
                }

            // Senao, se a arvore tiver dois nomes (raiz e dir)
            } else if (raiz.esq == null) {
                comp++;
                if (nome.compareTo(raiz.nome) < 0) {
                    comp++;
                    raiz.esq = new No(nome);
                } else if (nome.compareTo(raiz.dir.nome) < 0) {
                    comp++;
                    raiz.esq = new No(raiz.nome);
                    raiz.nome = nome;
                } else {
                    raiz.esq = new No(raiz.nome);
                    raiz.nome = raiz.dir.nome;
                    raiz.dir.nome = nome;
                }
                raiz.esq.cor = raiz.dir.cor = false;

            // Senao, se a arvore tiver dois nomes (raiz e esq)
            } else if (raiz.dir == null) {
                comp++;
                if (nome.compareTo(raiz.nome) > 0) {
                    comp++;
                    raiz.dir = new No(nome);
                } else if (nome.compareTo(raiz.esq.nome) > 0) {
                    comp++;
                    raiz.dir = new No(raiz.nome);
                    raiz.nome = nome;
                } else {
                    raiz.dir = new No(raiz.nome);
                    raiz.nome = raiz.esq.nome;
                    raiz.esq.nome = nome;
                }
                raiz.esq.cor = raiz.dir.cor = false;

            // Senao, a arvore tem tres ou mais nomes
            } else {
                inserir(nome, null, null, null, raiz);
            }
            raiz.cor = false;
        }

        private void balancear(No bisavo, No avo, No pai, No i) {
            // Se o pai tambem e preto, reequilibrar a arvore, rotacionando o avo
            if (pai.cor == true) {
                comp++;
                // 4 tipos de reequilibrios e acoplamento
                if (pai.nome.compareTo(avo.nome) > 0) { // rotacao a esquerda ou direita-esquerda
                    comp++;
                    if (i.nome.compareTo(pai.nome) > 0) { 
                        comp++;
                        avo = rotacaoEsq(avo);
                    } else {
                        avo = rotacaoDirEsq(avo);
                    }
                } else { // rotacao a direita ou esquerda-direita
                    if (i.nome.compareTo(pai.nome) < 0) {
                        comp++;
                        avo = rotacaoDir(avo);
                    } else {
                        avo = rotacaoEsqDir(avo);
                    }
                }
                if (bisavo == null) {
                    comp++;
                    raiz = avo;
                } else if (avo.nome.compareTo(bisavo.nome) < 0) { 
                    comp++;
                    bisavo.esq = avo;
                } else {
                    bisavo.dir = avo;
                }
                // reestabelecer as cores apos a rotacao
                avo.cor = false;
                avo.esq.cor = avo.dir.cor = true;
            } // if(pai.cor == true)
        }

        private void inserir(String nome, No bisavo, No avo, No pai, No i) {
            if (i == null) {
                comp++;
                if (nome.compareTo(pai.nome) < 0) { 
                    comp++;
                    i = pai.esq = new No(nome, true);
                } else {
                    i = pai.dir = new No(nome, true);
                }
                if (pai.cor == true) {
                    comp++;
                    balancear(bisavo, avo, pai, i);
                }
            } else {
                // Achou um 4-no: eh preciso fragmeta-lo e reequilibrar a arvore
                if (i.esq != null && i.dir != null && i.esq.cor == true && i.dir.cor == true) {
                    comp++;
                    i.cor = true;
                    i.esq.cor = i.dir.cor = false;
                    if (i == raiz) {
                        comp++;
                        i.cor = false;
                    } else if (pai.cor == true) {
                        comp++;
                        balancear(bisavo, avo, pai, i);
                    }
                }
                if (nome.compareTo(i.nome) < 0) { 
                    comp++;
                    inserir(nome, avo, pai, i, i.esq);
                } else if (nome.compareTo(i.nome) > 0) { 
                    comp++;
                    inserir(nome, avo, pai, i, i.dir);
                } 
            }
        }

        private No rotacaoDir(No no) {
            No noEsq = no.esq;
            No noEsqDir = noEsq.dir;

            noEsq.dir = no;
            no.esq = noEsqDir;

            return noEsq;
        }

        private No rotacaoEsq(No no) {
            No noDir = no.dir;
            No noDirEsq = noDir.esq;

            noDir.esq = no;
            no.dir = noDirEsq;
            return noDir;
        }

        private No rotacaoDirEsq(No no) {
            no.dir = rotacaoDir(no.dir);
            return rotacaoEsq(no);
        }

        private No rotacaoEsqDir(No no) {
            no.esq = rotacaoEsq(no.esq);
            return rotacaoDir(no);
        }

        public void buscar(String nome){
            MyIO.print("raiz ");
            buscar (raiz, nome);
        }

        public void buscar(No tmp, String nome){
            if (tmp.nome.compareTo(nome) > 0){
                comp++;
                if(tmp.esq == null){
                    comp++;
                    MyIO.println("esq NAO");
                } else {
                    MyIO.print("esq ");
                    buscar(tmp.esq, nome);
                }
            } else if (tmp.nome.compareTo(nome) < 0){
                comp++;
                if(tmp.dir == null){
                    comp++;
                    MyIO.println("dir NAO");
                } else {
                    MyIO.print("dir ");
                    buscar(tmp.dir, nome);
                }
            } else if (tmp.nome.equals(nome)){
                comp++;
                MyIO.println("SIM");
            }
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
        Arvore arv = new Arvore();
        String str = "";
        double inicio, fim;

        inicio = System.currentTimeMillis();

        while (!entrada.equals("FIM")){
            entrada = MyIO.readString();
            if(!entrada.equals("FIM")){
                str = ler(Integer.parseInt(entrada));
                arv.inserir(str);
            } 
        }
        do{
            entrada = MyIO.readLine();
            if(!entrada.equals("FIM")){
                MyIO.print(entrada + " ");
                arv.buscar(entrada);
            }
        } while (!entrada.equals("FIM"));

        fim = System.currentTimeMillis();

        String tempo = (fim-inicio)/1000 + "\t";
        String conteudo = "816479\t" + tempo + comp;
        Arq.openWriteClose("816479_avinegra.txt", conteudo);
    }
}