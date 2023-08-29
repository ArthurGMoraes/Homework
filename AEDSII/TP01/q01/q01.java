class q01{
    public static void main (String[] args){
        MyIO myIo = new MyIO();
        String palavra;
        do{
            palavra = myIo.readLine();
            if (!palavra.equalsIgnoreCase("FIM")){
                myIo.println(palindromo(palavra));
            }
        } while (!palavra.equalsIgnoreCase("FIM"));
    }

    public static String palindromo (String palavra){
        MyIO myIo = new MyIO();
        int tamanho = palavra.length();      // int tamanho = palavra.length() - 1; para linux, porem no verde da menos %
        //myIo.println(tamanho);
        int i = 0;
        int f = tamanho - 1;
        String resposta = "";
        for(i = 0; i < tamanho/2; i++ , f--){
            //myIo.println(palavra.charAt(i));
            //myIo.println(palavra.charAt(f));
            if (palavra.charAt(i) == palavra.charAt(f)){
                resposta = "SIM";
            } else {
                resposta = "NAO";
                i = tamanho;
            }
        }
        return resposta;
    }
}