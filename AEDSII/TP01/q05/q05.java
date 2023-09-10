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
                }   
                expressao = myIo.readLine();
                expressao = trocaOperadores(expressao);
            }
        } while (tamanho > 0);             // Loop para executar a funcao enquanto o tamanho for > 0
    }

    public static String fazerBool(String exp){
        int tamanho = exp.length();
        
        for (int i = 0; i < tamanho, i++){
            if (exp.charAt(i) == 'a' && exp.charAt(i+1) == 'n' && exp.charAt(i+2) == 'd'){
                if(char)  
            }
        }
        return "SIM";
    }
}