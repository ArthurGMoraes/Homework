class q01{
    public static void main (String[] args){

        // Inicializando variaveis e MyIO
        MyIO myIo = new MyIO();
        myIo.setCharset("ASCII");
        String palavra;

        do{
            palavra = myIo.readLine();
            if (!palavra.equalsIgnoreCase("FIM")){
                myIo.println(palindromo(palavra));
            }
        } while (!palavra.equalsIgnoreCase("FIM"));  // Loop para executar a funcao palindromo enquanto palavra != FIM
    }

    public static String palindromo (String palavra){

        // Inicializando variaveis e MyIo
        MyIO myIo = new MyIO();
        int tamanho = palavra.length();      
        //myIo.println(tamanho);
        int i = 0;                          // contador comecando da posicao inicial
        int f = tamanho - 1;                // contador comecando da posicao final
        String resposta = "";               

        // loop para conferir se a palavra é um palindromo
        for(i = 0; i < tamanho/2; i++ , f--){        // percorre dos extremos ate o centro comparando as letras           
            //myIo.println(palavra.charAt(i));
            //myIo.println(palavra.charAt(f));
            if (palavra.charAt(i) == palavra.charAt(f)){
                resposta = "SIM";
            } else {
                resposta = "NAO";
                i = tamanho;           // caso uma letra nao seja compativel a funcao e' encerrada
            }
        }
        return resposta;
    }
}