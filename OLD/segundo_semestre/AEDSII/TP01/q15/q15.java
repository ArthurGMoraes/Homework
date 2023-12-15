class q15{
    public static void main (String[] args){
        // Inicializando variaveis e MyIO
        MyIO myIo = new MyIO();
        String palavra = "";
        do{
            palavra = myIo.readLine();
            if (!palavra.equalsIgnoreCase("FIM")){
                vogal(palavra, 0, false);
                consoante(palavra, 0, false);
                numero(palavra, 0, false);
                real(palavra, 0 , false, 0); 
                myIo.println("");
            }
        } while (!palavra.equalsIgnoreCase("FIM"));             // Loop para executar as funcoes enquanto palavra != FIM
    }

    // Funcao que confere se todos os caracteres sao vogais
    public static void vogal(String palavra, int i, boolean result){
        MyIO myIo = new MyIO();
        int tamanho = palavra.length();
        if (i < tamanho){
            if (palavra.charAt(i) != 'a' && palavra.charAt(i) != 'A' && palavra.charAt(i) != 'e' && palavra.charAt(i) != 'E' &&
                palavra.charAt(i) != 'i' && palavra.charAt(i) != 'I' && palavra.charAt(i) != 'o' && palavra.charAt(i) != 'O' &&
                palavra.charAt(i) != 'u' && palavra.charAt(i) != 'U'){    // confere se o caracter nao e' vogal
                    result = false;
                    i = tamanho;                 // caso algum caractere nao seja voga a funcao pode ser encerrada e seu resultado sera false
                    vogal(palavra, i, result);
                } else {
                    vogal(palavra, i + 1, true);
                }
        } else {
            myIo.print(result?"SIM ":"NAO ");
        }
    }

    // Funcao que confere se todos os caracteres sao consoantes
    public static void consoante(String palavra, int i, boolean result){
        MyIO myIo = new MyIO();
        int tamanho = palavra.length();
        if (i < tamanho){
            if (palavra.charAt(i) == 'a' || palavra.charAt(i) == 'A' || palavra.charAt(i) == 'e' || palavra.charAt(i) == 'E' ||
                palavra.charAt(i) == 'i' || palavra.charAt(i) == 'I' || palavra.charAt(i) == 'o' || palavra.charAt(i) == 'O' ||
                palavra.charAt(i) == 'u' || palavra.charAt(i) == 'U'){    // como as vogais sao letras verifica-se se ha a presenca de alguma antes de verificarmos se o caracter e' diferentede letra
                    result = false;
                    i = tamanho;
                    consoante(palavra, i, result);
                } else if (!(palavra.charAt(i) >= 'a' && palavra.charAt(i) <= 'z') && !(palavra.charAt(i) >= 'A' && palavra.charAt(i) <= 'Z' )){ // verifica se o caracter e' diferente de letra
                        result = false;
                        i = tamanho;            // caso algum seja diferente de letra a funcao e' encerrada e retorna false
                        consoante(palavra, i, result);
                } else {
                    consoante(palavra, i + 1, true);
                }
        } else {
            myIo.print(result?"SIM ":"NAO ");
        }
    }

    // Verifica se todos os caracteres sao numeros
    public static void numero(String palavra, int i, boolean result){
        MyIO myIo = new MyIO();
        int tamanho = palavra.length();
        if ( i < tamanho){
            if (!(palavra.charAt(i) >= '0' && palavra.charAt(i) <= '9')){ 
                result = false;
                i = tamanho;
                numero(palavra, i, result);
            } else {
                numero(palavra, i + 1, true);
            }
        } else {
            myIo.print(result?"SIM ":"NAO ");
        }
    }

    // Verifica se a entrada e' um numero real
    public static void real(String palavra, int i, boolean result, int contador){
        MyIO myIo = new MyIO();
        int tamanho = palavra.length();

        if (i < tamanho){
            if (!(palavra.charAt(i) >= '0' && palavra.charAt(i) <= '9')){  // confere se o caractere e' != de numero
                //myIo.println("nao num");

                if (palavra.charAt(i) == ',' || palavra.charAt(i) == '.'){  // numeros reais possuem caracteres nao numeros, portanto aqui conferimos se o caracter faz parte dos numero real
                    real(palavra, i + 1, true, contador + 1);    // um numero real so possui um ponto ou virgula
                } else {
                    //myIo.println("else");
                    result = false;             // a entrada possui algum caractere que nao faz parte de um numero real e portanto seu resultado e' falso
                    i = tamanho;                // encerra o loop
                    real(palavra, i, result, contador); 
                }
            } else {
                real(palavra, i + 1 , true, contador);  
            }
           //myIo.println(i);
           //myIo.println(result);
        } else {
            //myIo.println(result + "ante if");
            if ((result == true) && contador > 1){   // confere se o numero de virgulas e/ou pontos e' maior que 1
                result = false;                      
                //myIo.println("if");
            }
            myIo.print(result?"SIM":"NAO");
            //myIo.println(result + "fim");
        } 
    }
}