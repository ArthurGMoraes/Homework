import java.util.Random;

class q04{
    public static void main (String[] args){
        //Inicializacao de variaveis, MyIO e Random
        Random gerador = new Random( );
        MyIO myIo = new MyIO();
        gerador . setSeed ( 4 );
        String palavra;

        do{
            palavra = myIo.readLine();
            if (!palavra.equalsIgnoreCase("FIM")){
                myIo.println(rand(palavra, (char)('a'+ Math.abs(gerador.nextInt()) % 26), (char)('a'+Math.abs(gerador.nextInt()) % 26)));    // a entrada e dois caracteres gerados aleatoriamente sao passados para a funcao
            }
        } while (!palavra.equalsIgnoreCase("FIM"));             // Loop para executar a funcao rand enquanto palavra != FIM
    }

    public static String rand (String palavra, char base, char troca){
    
        // Inicializacao de variaveis
        int tamanho = palavra.length();
        int i = 0;
        String resposta = "";

        // Loop percorre toda a string alterando o caracter da base pelo da troca
        for (i = 0; i < tamanho; i++){ 
            if(palavra.charAt(i) == base){
                resposta += troca;                             // troca de caracter
            } else {
                resposta += palavra.charAt(i);                 // formar string com as letras ao alteradas
            }
        } 
        return resposta;
    }
}