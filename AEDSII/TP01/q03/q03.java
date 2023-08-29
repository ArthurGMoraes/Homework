class q03 {
    public static void main(String[] args) {
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
        } while (!input.equalsIgnoreCase("FIM"));
    }

    public static String encrypt(String input) {
        String encryptedText = "";
        for (int i = 0; i < input.length(); i++) {
            char currentChar = input.charAt(i);
            char encryptedChar = (char)(currentChar + 3);

            encryptedText += encryptedChar;
        }
        return encryptedText;
    }
}