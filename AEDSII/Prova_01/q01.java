// Arthur Goncalves de Moraes

class q01{
    public static void main (String[] args){
        MyIO myIo = new MyIO();
        String input1;
        String input2;

        int quantidade = myIo.readInt();

        for (int i = 0; i < quantidade; i++){
            input1 = myIo.readString();
            input2 = myIo.readString();
            myIo.println(avancarLetra(input1, input2));
        }
    }

    public static int avancarLetra(String input1, String input2){
        int tamanho = input1.length();
        int contador = 0;
        int antigo = 0;     
        int i = 0;

        for  (i = 0; i < tamanho; i++){
            if (input1.charAt(i) != input2.charAt(i)){
                antigo = contador;
                if ((int) input1.charAt(i) < ((int) input2.charAt(i))){
                    contador += contador + (((int) input1.charAt(i) - ((int) input2.charAt(i)))%26)*(-1);
                } else {
                    contador += contador + (((int) 'z' - ((int) input1.charAt(i)))%26) + (((int) input2.charAt(i) - (int)'a')%26) + 1;
                }
                contador = contador - antigo;
                //System.out.println(contador);
            }
        }

        return contador;
    }
}
