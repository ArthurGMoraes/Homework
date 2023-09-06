import java.util.*;
import java.io.*;
import java.nio.charset.*;

class espelho{
    private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in, Charset.forName("ISO-8859-1")));
    public static void main (String[] args){
        MyIO myIo = new MyIO();
        char tmp = ' ';
        String ini = "";
        int inicio = 0;
        int fim = 0;

        do{
            try{
                do{
                tmp = (char)in.read();
                if(tmp != '\n' && tmp != ' ' && tmp != 13 && tmp != '?'){
                ini += tmp;
                }
                }while(tmp != '\n' && tmp != ' ' && tmp != '?');
            }catch(IOException ioe){}
            
            if (tmp != '?'){
                inicio = Integer.valueOf(ini);
                fim = myIo.readInt();
                //myIo.println(fim);
                imprimir(inicio, fim);
                myIo.println("");
            }
        } while (tmp != '?');
    }

    public static void imprimir(int inicio, int fim){
        MyIO myIo = new MyIO();
        int copiaInicio = inicio;
        while (inicio <= fim){
            myIo.print(inicio);
            inicio = inicio + 1;
        }
        inicio = inicio - 1;
        while (inicio >= copiaInicio){
            myIo.print(inicio);
            inicio = inicio - 1;
        }
    }
}