import java.util.Random;

class q04{
    public static void main (String[] args){
        Random gerador = new Random( );
        MyIO myIo = new MyIO();
        gerador . setSeed ( 4 );

        String palavra;
        do{
            palavra = myIo.readLine();
            if (!palavra.equalsIgnoreCase("FIM")){
                myIo.println(rand(palavra, (char)('a'+ Math.abs(gerador.nextInt()) % 26), (char)('a'+Math.abs(gerador.nextInt()) % 26)));
            }
        } while (!palavra.equalsIgnoreCase("FIM"));
    }

    public static String rand (String palavra, char base, char troca){
        Random gerador = new Random( );
        MyIO myIo = new MyIO();
        gerador . setSeed ( 4 );

        int tamanho = palavra.length();
        int i = 0;
        String resposta = palavra;

        for (i = 0; i < tamanho; i++){
            if(palavra.charAt(i) == base){
                resposta = resposta.substring(0, i) + troca + resposta.substring(i + 1);
            } 
        } 
        return resposta;
    }
}