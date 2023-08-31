class q06{
    public static void main (String[] args){
        // Inicializando variaveis e MyIO
        MyIO myIo = new MyIO();
        String palavra = "";
        String x1 = "";
        String x2 = "";
        String x3 = "";
        String x4 = "";
        do{
            palavra = myIo.readLine();
            if (!palavra.equalsIgnoreCase("FIM")){
                x1 = vogal(palavra) ? "SIM":"NAO";           // resultados x1,x2,x3 e x4 formatados
                x2 = consoante(palavra) ? "SIM":"NAO";
                x3 = numero(palavra) ? "SIM":"NAO";
                x4 = real(palavra) ? "SIM":"NAO";
                myIo.println( x1 + " " + x2  + " " + x3 + " " + x4);  // saida dos resultados formatados
            }
        } while (!palavra.equalsIgnoreCase("FIM"));             // Loop para executar as funcoes enquanto palavra != FIM
    }

    // Funcao que confere se todos os caracteres sao vogais
    public static boolean vogal(String palavra){
        int tamanho = palavra.length();
        boolean result = true;
        for (int i = 0; i < tamanho; i++){
            if (palavra.charAt(i) != 'a' && palavra.charAt(i) != 'A' && palavra.charAt(i) != 'e' && palavra.charAt(i) != 'E' &&
                palavra.charAt(i) != 'i' && palavra.charAt(i) != 'I' && palavra.charAt(i) != 'o' && palavra.charAt(i) != 'O' &&
                palavra.charAt(i) != 'u' && palavra.charAt(i) != 'U'){    // confere se o caracter nao e' vogal
                    result = false;
                    i = tamanho;                 // caso algum caractere nao seja voga a funcao pode ser encerrada e seu resultado sera false
                }
        }
        return result;
    }

    // Funcao que confere se todos os caracteres sao consoantes
    public static boolean consoante(String palavra){
        int tamanho = palavra.length();
        boolean result = true;
        for (int i = 0; i < tamanho; i++){
            if (palavra.charAt(i) == 'a' || palavra.charAt(i) == 'A' || palavra.charAt(i) == 'e' || palavra.charAt(i) == 'E' ||
                palavra.charAt(i) == 'i' || palavra.charAt(i) == 'I' || palavra.charAt(i) == 'o' || palavra.charAt(i) == 'O' ||
                palavra.charAt(i) == 'u' || palavra.charAt(i) == 'U'){    // como as vogais sao letras verifica-se se ha a presenca de alguma antes de verificarmos se o caracter e' diferentede letra
                    result = false;
                    i = tamanho;
                } else if (!(palavra.charAt(i) >= 'a' && palavra.charAt(i) <= 'z')){ // verifica se o caracter e' diferente de letra
                    if (!(palavra.charAt(i) >= 'A' && palavra.charAt(i) <= 'Z')){
                        result = false;
                        i = tamanho;            // caso algum seja diferente de letra a funcao e' encerrada e retorna false
                    }
                }
        }
        return result;
    }

    // Verifica se todos os caracteres sao numeros
    public static boolean numero(String palavra){
        int tamanho = palavra.length();
        boolean result = true;
        for (int i = 0; i < tamanho; i++){
            if (!(palavra.charAt(i) >= '0' && palavra.charAt(i) <= '9')){ 
                result = false;
                i = tamanho;
            }
        }
        return result;
    }

    // Verifica se a entrada e' um numero real
    public static boolean real(String palavra){
        MyIO myIo = new MyIO();
        int tamanho = palavra.length();
        int contador = 0;
        boolean result = true;

        for (int i = 0; i < tamanho; i++){
            if (!(palavra.charAt(i) >= '0' && palavra.charAt(i) <= '9')){  // confere se o caractere e' != de numero
                //myIo.println("nao num");

                if (palavra.charAt(i) == ',' || palavra.charAt(i) == '.'){  // numeros reais possuem caracteres nao numeros, portanto aqui conferimos se o caracter faz parte dos numero real
                    contador++;    // um numero real so possui um ponto ou virgula
                } else {
                    //myIo.println("else");
                    result = false;             // a entrada possui algum caractere que nao faz parte de um numero real e portanto seu resultado e' falso
                    i = tamanho;                // encerra o loop
                }
            }
           //myIo.println(i);
           //myIo.println(result);
        }
       //myIo.println(result + "ante if");
        if ((result == true) && contador > 1){   // confere se o numero de virgulas e/ou pontos e' maior que 1
            result = false;                      
            //myIo.println("if");
        }

        //myIo.println(result + "fim");
        return result;
    }
}