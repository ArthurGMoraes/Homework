import java.util.*;

class q02{
    public static int comp = 0;

    public static class No{
        private int altura;
        private No dir;
        private No esq;
        private No2 topo;

        public No(int altura){
            this.altura = altura;
            dir = null;
            esq = null;
            topo = null;
        }
    }

    public static class No2{
        private String nome;
        private No2 dir;
        private No2 esq;

        public No2(String nome){
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
            } else if (tmp.altura > no.altura){
                comp++;
                if(tmp.esq == null){
                    tmp.esq = no;
                    comp++;
                } else {
                    inserirNo(tmp.esq, no);
                }
            } else if (tmp.altura < no.altura){
                comp++;
                if(tmp.dir == null){
                    comp++;
                    tmp.dir = no;
                } else {
                    inserirNo(tmp.dir, no);
                }
            }
        }

        public void caminharPre(String nome){
            MyIO.print("raiz ");
            caminharPre(raiz, "esq ", nome);
        }

        public void caminharPre(No i, String pos, String nome) {
            String achou = "";
		    if (i != null) {
                MyIO.print(pos);
                achou = buscar(i.topo, nome);
			    caminharPre(i.esq, "esq ", nome); // Elementos da esquerda.
			    caminharPre(i.dir, "dir ", nome); // Elementos da direita.
		    } else {
                MyIO.print(achou);
            }
            
            
	    }

        public void buscar(String nome){
            caminharPre(nome);
        }

        public String buscar(No2 tmp, String nome){
           String result = "";
            if (tmp == null){
                MyIO.println("NULL");
                result = "NAO";
            } else if (tmp.nome.compareTo(nome) > 0){
                comp++;
                if(tmp.esq == null){
                    comp++;
                    MyIO.print("ESQ ");
                    result =  "NAO";
                } else {
                    MyIO.print("ESQ ");
                    result = buscar(tmp.esq, nome);
                }
            } else if (tmp.nome.compareTo(nome) < 0){
                comp++;
                if(tmp.dir == null){
                    comp++;
                    MyIO.print("DIR ");
                    result ="NAO";

                } else {
                    MyIO.print("DIR ");
                    result = buscar(tmp.dir, nome);
                }
            } else if (tmp.nome.equals(nome)){
                comp++;
                result = "SIM";
            }
            return result;
        }   

        public void inserirNome(int buscar, No2 no){
            inserirNome(raiz, buscar, no);
        }

        public void inserirNome(No tmp, int buscar, No2 no){
            if(buscar > tmp.altura){
                inserirNome(tmp.dir, buscar, no);
            } else if (buscar < tmp.altura){
                inserirNome(tmp.esq, buscar, no);
            } else if (buscar == tmp.altura){
                inserirNome(tmp.topo, no);
            }
        }

        public void inserirNome(No2 tmp2, No2 no){
            if(tmp2 == null){
                tmp2 = no;
                comp++;
            } else if (tmp2.nome.compareTo(no.nome) > 0){
                comp++;
                comp++;
                if(tmp2.esq != null){
                    inserirNome(tmp2.esq, no);
                } else {
                    tmp2.esq = no;
                }
                
            } else if (tmp2.nome.compareTo(no.nome) < 0){
                comp++;
                comp++;
                if(tmp2.esq != null){
                    inserirNome(tmp2.dir, no);
                } else {
                    tmp2.dir = no;
                }
            }
        }
    }

    public static String lerNome(int id){
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

    public static int lerAltura(int id){
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
            
            str = parts[2];
            MyIO.println(str);
            return Integer.parseInt(str);
    }

    public static void main(String[] args){
        String entrada = "";
        Arvore arv = new Arvore();
        String str = "";
        double inicio, fim;
        arv.inserirNo(new No(7));
        arv.inserirNo(new No(3));
        arv.inserirNo(new No(11));
        arv.inserirNo(new No(1));
        arv.inserirNo(new No(5));
        arv.inserirNo(new No(9));
        arv.inserirNo(new No(13));
        arv.inserirNo(new No(0));
        arv.inserirNo(new No(2));
        arv.inserirNo(new No(4));
        arv.inserirNo(new No(6));
        arv.inserirNo(new No(8));
        arv.inserirNo(new No(10));
        arv.inserirNo(new No(12));
        arv.inserirNo(new No(14));

        inicio = System.currentTimeMillis();

        while (!entrada.equals("FIM")){
            entrada = MyIO.readString();
            if(!entrada.equals("FIM")){
                str = lerNome(Integer.parseInt(entrada));
                No2 no2 = new No2(str);
                arv.inserirNome(lerAltura(Integer.parseInt(entrada))%15, no2);
            } 
        }
        do{
            entrada = MyIO.readLine();
            if(!entrada.equals("FIM")){
                MyIO.print(entrada + " ");
                arv.buscar(entrada);
                MyIO.println(" ");
            }
        } while (!entrada.equals("FIM"));

        fim = System.currentTimeMillis();

        String tempo = (fim-inicio)/1000 + "\t";
        String conteudo = "816479\t" + tempo + comp;
        Arq.openWriteClose("816479_arvoreArvore.txt", conteudo);
    }
}