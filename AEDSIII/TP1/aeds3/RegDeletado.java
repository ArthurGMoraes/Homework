package aeds3;

import java.util.*;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.io.FileNotFoundException;
import java.io.File;
import java.lang.reflect.Constructor;



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
        private short quantidade;
        public String nomeArquivo;
        RandomAccessFile arquivo;

        public RegDeletado(String nd) throws Exception{
            inicio = null;
            nomeArquivo = nd;
            quantidade = 0;
        
                lerArq();
            
            
        }

        public void inserir(long pos, int tam)throws Exception{
            Obj registro = new Obj(pos, tam);
           

            if(inicio == null){
                inicio = registro;
                quantidade++;
            } else if(quantidade < 300) {
                Obj i;
                for (i = inicio; i.prox != null; i = i.prox);
                i.prox = registro;
                quantidade++;
            }
        

            //System.out.println(inicio.endereco + " INI " + inicio.tam);
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


        public Obj remover(long pos) throws Exception{
            Obj removido = null;
            Obj i = inicio;
            Obj j = inicio;
            Obj tmp;
            if (inicio != null){
                if (inicio.endereco == pos){
                    removido = inicio;
                    inicio=inicio.prox;
                    quantidade--;
                    //System.out.println(inicio.endereco + " " + inicio.prox + "RE INI");
                }else {
                    while (i.endereco != pos ){
                        j = i;
                        i = i.prox;
                    }
                    tmp = i.prox;
                    removido = i;
                    j.prox = tmp;
                    quantidade--;
                    //System.out.println(i.endereco + " " + j.endereco + " " + inicio.endereco + "RE");
                }
                
            }   
            return removido;
        }

      public void escreverArq() throws Exception {
            //System.out.print("dados/" + nomeArquivo);
            arquivo = new RandomAccessFile("dados/" + nomeArquivo, "rw");
            arquivo.writeShort(quantidade);
            for (Obj i = inicio; i != null; i = i.prox) {
                // System.out.print(i.endereco + " " + i);
                arquivo.writeLong(i.endereco);
                arquivo.writeShort(i.tam);
            }
        //System.out.println("");
    }

    public void lerArq() throws Exception {
            arquivo = new RandomAccessFile("dados/" + nomeArquivo, "rw");
            if(arquivo.read() != -1){
                arquivo.seek(0);
            short quantidade2 = arquivo.readShort();
            if (quantidade2 > 0){
            int i = 0;
            int tamanho = 0;
            long endereco = 0;
            while (i < quantidade2) {
                endereco = arquivo.readLong();
                tamanho = arquivo.readShort();
                inserir(endereco, tamanho);
                i++;
            }
            }
            }
    }




}