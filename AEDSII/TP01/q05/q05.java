class q05{
    public static void main (String[] args){
        // Inicializando MyIO e variaveis
        MyIO myIo = new MyIO();
        int tamanho = 0;
        String expressao = "";

        // Recebendo entradas ate receber 0 como tamanho
        do{
            tamanho = myIo.readInt();
            if (tamanho > 0){
                int[] valores = new int[tamanho];
                for (int i = 0; i < tamanho; i++){
                    valores[i] = myIo.readInt();
                    //myIo.println(valores[i]);
                }   
                expressao = myIo.readString();
                myIo.println(expressao);
            }
        } while (tamanho > 0);             // Loop para executar a funcao enquanto o tamanho for > 0
    }

    public static String and(int[] valores){

        
        return "SIM";
    }
}