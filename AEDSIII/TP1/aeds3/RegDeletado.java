package aeds3;

import java.util.*;



public class RegDeletado{
    public static class Obj{
        public long endereco;
        public int tam;
        public Obj prox;
        
        public Obj(long endereco, int tam){
            this.endereco = endereco;
            this.tam = tam;
            prox = null;
        }
    }
        
        public Obj inicio;
        private int n;

        public RegDeletado(){
            inicio = null;
            n = 0;
        }

        public void inserir(long pos, int tam){
            Obj registro = new Obj(pos, tam);
           

            if(inicio == null){
                inicio = registro;
                n++;
            } else {
                Obj i;
                for (i = inicio; i.prox != null; i = i.prox);
                i.prox = registro;
                n++;
            }

            //System.out.println(inicio.endereco + " INI " + inicio.tam);
        }

        public boolean isEmpty(){
            if (inicio == null){
                return true;
            }
                
            return false;
        }

        public int getMaior(){
            int maior = 0;
            for (Obj i = inicio; i != null; i = i.prox){
                if (i.tam > maior ){
                    maior = i.tam;
                }
            }
            return maior;
        }

        public long conferir(int t){
            //System.out.println("TAM A ENSERIR " + t);
            long pos = -1;
            int melhor = getMaior();
            for (Obj i = inicio; i != null; i = i.prox){
                //System.out.println("TAM ESPACO" + i.tam + " TAM MELHOR " + melhor);
                if (t >= i.tam * 0.7 && t <= i.tam){
                    if (i == inicio){
                        pos = i.endereco;
                    }
                    if (i.tam < melhor){
                        pos = i.endereco;
                        melhor = i.tam;
                    }
                }
            }
            //System.out.println(pos);
            return pos;
        }


        public Obj remover(int pos){
            Obj removido = null;
            Obj j = inicio;
            if (inicio != null){
                for (int i = 0; i < pos - 1; i++){
                    j = j.prox;
                }
                Obj tmp = j.prox.prox;
                removido = j.prox;
                j.prox = tmp;
                n--;
            }
            return removido;
        }


}