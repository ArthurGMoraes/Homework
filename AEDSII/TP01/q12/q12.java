class q12 {
    public static void main(String[] args) {
        // Inicializacao de variaveis e MyIo
        MyIO myIo = new MyIO();
        String input;
        
        do {
            input = myIo.readLine();
            
            if (!input.equalsIgnoreCase("FIM")) {
                encrypt(input, 0, "");
                //myIo.setCharset("ASCII");
                
                //System.out.println(encryptedText);
            }
        } while (!input.equalsIgnoreCase("FIM"));                // Loop para executar a funcao encrypt enquanto palavra != FIM
    }

    public static void encrypt(String input, int i, String encryptedText) {
        MyIO myIo = new MyIO();
        // Loop para encriptar letra por letra -> percorre toda a string
        if (i < input.length()){
            char currentChar = input.charAt(i);
            char encryptedChar = (char)(currentChar + 3);

            encryptedText += encryptedChar;                     // forma uma nova string com os caracteres encriptados
            encrypt(input, i + 1, encryptedText);
        }
        else{
            myIo.println(encryptedText);
        }
    }
}