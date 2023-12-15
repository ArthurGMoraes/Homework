class q03 {
    public static void main(String[] args) {
        // Inicializacao de variaveis e MyIo
        MyIO myIo = new MyIO();
        String input;
        
        do {
            input = myIo.readLine();
            
            if (!input.equalsIgnoreCase("FIM")) {
                String encryptedText = encrypt(input);
                //myIo.setCharset("ASCII");
                myIo.println(encryptedText);
                //System.out.println(encryptedText);
            }
        } while (!input.equalsIgnoreCase("FIM"));                // Loop para executar a funcao encrypt enquanto palavra != FIM
    }

    public static String encrypt(String input) {
        // Inicializacao de variaveis
        String encryptedText = "";

        // Loop para encriptar letra por letra -> percorre toda a string
        for (int i = 0; i < input.length(); i++) {
            char currentChar = input.charAt(i);
            char encryptedChar = (char)(currentChar + 3);

            encryptedText += encryptedChar;                     // forma uma nova string com os caracteres encriptados
        }
        return encryptedText;
    }
}