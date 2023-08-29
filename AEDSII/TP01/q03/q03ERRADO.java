class q03ERRADO {
    public static void main(String[] args) {
        String input;

        do {
            input = MyIO.readLine();
            
            if (!input.equalsIgnoreCase("FIM")) {
                String encryptedText = encrypt(input);
                MyIO.println(encryptedText);
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