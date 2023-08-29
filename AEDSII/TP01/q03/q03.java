import java.util.*;

class q03 {
    public static void main(String[] args) {
        MyIO myIo = new MyIO();
        //myIo.setCharset("UTF-8");
        String input;
        do {
            input = myIo.readLine();
            char[] cifra = new char[input.length()];
            if (!input.equalsIgnoreCase("FIM")) {
               encrypt(input, cifra);
               myIo.println(new String(cifra));
            }
        } while (!input.equalsIgnoreCase("FIM"));
    }

    public static void encrypt(String input, char[] s) {
        for (int i = 0; i < input.length(); i++) {   
                s[i] = (char) (input.charAt(i) + 3);
        }
    }
}