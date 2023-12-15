class q10{
    public static void main (String[] args){

        // Inicializando variaveis e MyIO
        MyIO myIo = new MyIO();
        myIo.setCharset("ASCII");
        String palavra;

        do{
            palavra = myIo.readLine();
            if (!palavra.equalsIgnoreCase("FIM")){
                palindromo(palavra, 0, palavra.length()-1, "resposta");
            }
        } while (!palavra.equalsIgnoreCase("FIM"));  // Loop para executar a funcao palindromo enquanto palavra != FIM
    }

    public static void palindromo (String palavra, int i, int f, String resposta){   // i = contador comecando da posicao inicial, f = contador comecando da posicao final

        // Inicializando variaveis e MyIo
        MyIO myIo = new MyIO();
        int tamanho = palavra.length();      
        //myIo.println(tamanho); 
        //myIo.println(i + " " + f);                            


        if(i < tamanho/2){
             if (palavra.charAt(i) == palavra.charAt(f)){
                //myIo.println(palavra.charAt(i) + " " + (palavra.charAt(f)));
                resposta = "SIM";
                palindromo(palavra, i+1, f-1, resposta);
            } else {
                resposta = "NAO";
                myIo.println(resposta);
                i = tamanho;           // caso uma letra nao seja compativel a funcao e' encerrada
            }
        } else {
            myIo.println(resposta);
        }
    }
}