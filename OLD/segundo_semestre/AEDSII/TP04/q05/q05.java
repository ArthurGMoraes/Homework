import java.util.*;

class q05{
    public static int comp = 0;
    public static class No{
        private String nome;
        private No dir;
        private No esq;

        public No(String nome){
            this.nome = nome;
            dir = null;
            esq = null;
        }
    }

    public static class Arvore{
        private No raiz;

        public Arvore(){
            raiz = null;
        }

        public void inserirNo(No no){
            inserirNo(raiz, no);
        }

        public void inserirNo(No tmp, No no){
            if(raiz == null){
                raiz = no;
                comp++;
            } else if (tmp.nome.compareTo(no.nome) > 0){
                comp++;
                if(tmp.esq == null){
                    tmp.esq = no;
                    comp++;
                } else {
                    inserirNo(tmp.esq, no);
                }
            } else if (tmp.nome.compareTo(no.nome) < 0){
                comp++;
                if(tmp.dir == null){
                    comp++;
                    tmp.dir = no;
                } else {
                    inserirNo(tmp.dir, no);
                }
            }
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

        public void caminharCentral() {
		    caminharCentral(raiz);
	    }

	
	    private void caminharCentral(No i) {
		    if (i != null) {
			    caminharCentral(i.esq); // Elementos da esquerda.
			    MyIO.println(i.nome); // Conteudo do no.
			    caminharCentral(i.dir); // Elementos da direita.
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
                No no = new No(str);
                arv.inserirNo(no);
            } 
        }

        arv.caminharCentral();

        fim = System.currentTimeMillis();

        String tempo = (fim-inicio)/1000 + "\t";
        String conteudo = "816479\t" + tempo + comp;
        Arq.openWriteClose("816479_treesort.txt", conteudo);
    }
}