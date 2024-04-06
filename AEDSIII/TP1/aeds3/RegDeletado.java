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

        public RegDeletado(String nd) throws FileNotFoundException, IOException{
            inicio = null;
            nomeArquivo = nd;
            quantidade = 0;
        
                fromByteArray();
            
            
        }

        public void inserir(long pos, int tam)throws FileNotFoundException, IOException{
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
                toByteArray();
        

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
                quantidade--;
            }
            return removido;
        }

      public void toByteArray() throws FileNotFoundException, IOException {
        
            arquivo = new RandomAccessFile("dados/" + nomeArquivo, "rw");
            arquivo.writeShort(quantidade);
            for (Obj i = inicio; i != null; i = i.prox) {
                arquivo.writeLong(i.endereco);
                arquivo.writeShort(i.tam);
            }
        
    }

    public void fromByteArray() throws FileNotFoundException, IOException {
      
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