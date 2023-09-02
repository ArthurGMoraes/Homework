import java.io.*;

public class q08 {
    
    public static void main (String args[])throws Exception
    {
        MyIO myIo = new MyIO();
        int quantidade = 0; 
        quantidade = myIo.readInt();
        RandomAccessFile Arq = new RandomAccessFile("resposta.txt", "rw"); 

        for(int i = 0; i < quantidade; i++) 
        {
            double numero = 0.0; 

            numero = myIo.readDouble(); //lendo um numero
            Arq.writeDouble(numero); 
        }
        Arq.close(); //salvando arquivo

        RandomAccessFile Arq2 = new RandomAccessFile("resposta.txt", "r"); //abrindo o arquivo novamente para leitura

        do
        {
            long position = (quantidade - 1) * 8;  //posicao baseada na quantidade de bytes
        
            Arq2.seek(position);  
        
            double Y = Arq2.readDouble();
            
            if (Y == (int) Y) 
            {
                System.out.println((int) Y);  
            } else {
                System.out.println(Y);  
            }
        
            quantidade--; //passando pra próxima posição
        } while (quantidade > 0);
        
        Arq2.close();
    }
}
