public class CifraDeCezar {
    public static void main (String args[])
    {
        String palavra;

        do
        {
            palavra = MyIO.readLine(); //recebendo a palavra da entrada
            char[] cifra = new char[palavra.length()];

            if(palavra.toUpperCase().equals("FIM")) //se a palavra for igual a FIM nada acontece
            {
                //nada acontece
            }
            else 
            {
                ciframento(palavra, cifra); //enviando a palavra para ciframento 
                System.out.println(new String(cifra));
            }
            

        }while (!palavra.toUpperCase().equals("FIM")); // fim da repetição
    }

    public static void ciframento(String palavra, char[] s) // função que recebe uma palavra e um array de caracteres para armazenar a cifra para 3
    {

        for(int i = 0; i < palavra.length(); i++) //percorrendo a palavra
        {
            if ((palavra.charAt(i) == 'x' || palavra.charAt(i) == 'X') || (palavra.charAt(i) == 'y' || palavra.charAt(i) == 'Y') || (palavra.charAt(i) == 'z' || palavra.charAt(i) == 'Z')) //para os ultimos 3 caracteres optei por mudar de forma individual para facilitar
            {
                if (palavra.charAt(i) == 'x' || palavra.charAt(i) == 'X')
                {
                    if (palavra.charAt(i) == 'x')
                    {
                        s[i] = 'a';
                    }
                    else
                    {
                        s[i] = 'A';
                    }
                }
                else if (palavra.charAt(i) == 'y' || palavra.charAt(i) == 'Y')
                {
                    if (palavra.charAt(i) == 'y')
                    {
                        s[i] = 'b';
                    }
                    else
                    {
                        s[i] = 'B';
                    }
                }
                else if (palavra.charAt(i) == 'z' || palavra.charAt(i) == 'Z')
                {
                    if (palavra.charAt(i) == 'z')
                    {
                        s[i] = 'c';
                    }
                    else
                    {
                        s[i] = 'C';
                    }
                }
            }
            else 
            {
                s[i] = (char) (palavra.charAt(i)+3); //o array recebe o caractere da palavra + 3
            }
        }

    }
}