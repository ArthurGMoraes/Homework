import java.io.*;
import java.net.*;
import java.nio.charset.*;

class q07{

     // verificar se e' <table>
    public static boolean isTable(String palavra)
    {
        return(palavra.length() == 7 && palavra.charAt(0) == '<' && palavra.charAt(1) == 't' && palavra.charAt(2) == 'a' && palavra.charAt(3) == 'b' &&
             palavra.charAt(4) == 'l' && palavra.charAt(5) == 'e' && palavra.charAt(6) == '>');
    }  

    // verificar se e' <br>
    public static boolean isBr(String palavra)
    {
        return(palavra.length() == 4 && palavra.charAt(0) == '<' && palavra.charAt(1) == 'b' && palavra.charAt(2) == 'r' && palavra.charAt(3) == '>');
    }

    public static void ler(String link, String nome)throws Exception
    {
        MyIO myIo = new MyIO();
        URL url = new URL(link); 
        InputStream is = url.openStream();  // throws an IOException
        BufferedReader leitor = new BufferedReader(new InputStreamReader(is, Charset.forName("UTF-8")));

        String palavra;
        int contador = 0;
        int consoantes = 0;
        int contadorA = 0;
        int contadorE = 0;
        int contadorI = 0;
        int contadorO = 0;
        int contadorU = 0;
        int contadorA1 = 0;
        int contadorE1 = 0;
        int contadorI1 = 0;
        int contadorO1 = 0;
        int contadorU1 = 0;
        int contadorA2 = 0;
        int contadorE2 = 0;
        int contadorI2 = 0;
        int contadorO2 = 0;
        int contadorU2 = 0;
        int contadorA3 = 0;
        int contadorO3 = 0;
        int contadorA4 = 0;
        int contadorE3 = 0;
        int contadorI3 = 0;
        int contadorO4 = 0;
        int contadorU3 = 0;
        int table= 0;
        int br = 0;

        
        while ((palavra = leitor.readLine()) != null)
        { 
            if(isTable(palavra))
            {
                table++;
            }
            else
            {
                if(isBr(palavra))
                {
                br++;
                }
                else
                {         
                while(contador < palavra.length())
                {
                    if('a' == palavra.charAt(contador))
                    {
                        contadorA++;
                    }
                    else
                    {
                        if('e' == palavra.charAt(contador))
                        {
                            contadorE++;
                        }
                        else
                        {
                            if('i' == palavra.charAt(contador))
                            {
                            contadorI++;
                            }
                            else
                            {
                            if('o' == palavra.charAt(contador))
                            {
                                contadorO++;
                            }
                            else
                            {
                                if('u' == palavra.charAt(contador))
                                {
                                    contadorU++;
                                }
                                else
                                {
                                    if('\u00E1' == palavra.charAt(contador))
                                    {
                                        contadorA1++;
                                    }      
                                    else
                                    {
                                        if('\u00E9' == palavra.charAt(contador))
                                        {
                                        contadorE1++;
                                        }     
                                        else
                                        {
                                        if('\u00ED' == palavra.charAt(contador))
                                        {
                                            contadorI1++;
                                        }   
                                        else
                                        {
                                            if('\u00F3' == palavra.charAt(contador))
                                            {
                                                contadorO1++;
                                            }
                                            else
                                            {
                                                if('\u00FA' == palavra.charAt(contador))
                                                {
                                                    contadorU1++;
                                                }
                                                else
                                                {
                                                    if('\u00E0' == palavra.charAt(contador))
                                                    {
                                                    contadorA2++;
                                                    }
                                                    else
                                                    {
                                                    if('\u00E8' == palavra.charAt(contador))
                                                    {
                                                        contadorE2++;
                                                    }           
                                                    else
                                                    {
                                                        if('\u00EC' == palavra.charAt(contador))
                                                        {
                                                            contadorI2++;
                                                        }           
                                                        else
                                                        {
                                                            if('\u00F2' == palavra.charAt(contador))
                                                            {
                                                                contadorO2++;
                                                            }           
                                                            else
                                                            {
                                                                if('\u00F9' == palavra.charAt(contador))
                                                                {
                                                                contadorU2++;
                                                                }           
                                                                else
                                                                {
                                                                if('\u00E3' == palavra.charAt(contador))
                                                                {
                                                                    contadorA3++;
                                                                }
                                                                else
                                                                {
                                                                    if('\u00F5' == palavra.charAt(contador))
                                                                    {
                                                                        contadorO3++;
                                                                    } 
                                                                    else
                                                                    {
                                                                        if('\u00E2' == palavra.charAt(contador))
                                                                        {
                                                                            contadorA4++;
                                                                        }   
                                                                        else
                                                                        {
                                                                            if('\u00EA' == palavra.charAt(contador))
                                                                            {
                                                                            contadorE3++;
                                                                            } 
                                                                            else
                                                                            {
                                                                            if('\u00EE' == palavra.charAt(contador))
                                                                            {
                                                                                contadorI3++;
                                                                            } 
                                                                            else
                                                                            {
                                                                                if('\u00F4' == palavra.charAt(contador))
                                                                                {
                                                                                    contadorO4++;
                                                                                }   
                                                                                else
                                                                                {
                                                                                    if('\u00FB' == palavra.charAt(contador))
                                                                                    {
                                                                                        contadorU3++;
                                                                                    }   
                                                                                    else
                                                                                    {
                                                                                        if('a' <= palavra.charAt(contador) && palavra.charAt(contador) <= 'z')//Todas as vogais foram testadas, caso seja uma letra automaticamente sera consoante
                                                                                        consoantes++;
                                                                                    }        
                                                                                }              
                                                                            }              
                                                                            }           
                                                                        }          
                                                                    }            
                                                                }           
                                                                } 
                                                            } 
                                                        }  
                                                    }  
                                                    }               
                                                }            
                                            }            
                                        }          
                                        }        
                                    }           
                                }              
                            }                  
                            }
                        }
                    }
                    contador++;
                }
                }
                contador++;
            }
            contador = 0;
        }
      myIo.println("a(" + contadorA + ") " + "e(" + contadorE + ") " + "i(" + contadorI + ") " + "o(" + contadorO + ") " + "u(" + contadorU + ") " + "á(" + contadorA1 + ") " + "é(" + contadorE1 + ") " +
                   "í(" + contadorI1 + ") " + "ó(" + contadorO1 + ") " + "ú(" + contadorU1 + ") " + "à(" + contadorA2 + ") " + "è(" + contadorE2 + ") " + "ì(" + contadorI2 + ") " + "ò(" + contadorO2 + ") " +
                   "ù(" + contadorU2 + ") " + "ã(" + contadorA3 + ") " + "õ(" + contadorO3 + ") " + "â(" + contadorA4 + ") " + "ê(" + contadorE3 + ") " + "î(" + contadorI3 + ") " + "ô(" + contadorO4 + ") " +
                   "û(" + contadorU3 + ") " + "consoante(" + consoantes + ") " + "<br>(" + br + ") " + "<table>(" +table + ") " +  nome );
      leitor.close();
    }

    public static void main(String[] args){
        MyIO myIo = new MyIO();
        String nome = "";
        String link = "";
        do{
            nome = myIo.readLine();
            if (!nome.equalsIgnoreCase("FIM")){
                link = MyIO.readLine();
                try {
                ler(link, nome);
            } catch (Exception e) {
                e.printStackTrace();
            }
            }
        } while (!nome.equalsIgnoreCase("FIM"));             // Loop para executar as funcoes enquanto palavra != FIM
    }

   
}