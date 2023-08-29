import java.util.*;

class q03 {
    public static void main(String[] args) {
       
        String input;
         
        int key = 3;

        do {
            input = MyIO.readLine();
            char[] cifra = new char[input.length()];
            
            if (!input.equalsIgnoreCase("FIM")) {
                 
               encrypt(input, cifra);
            }
        } while (!input.equalsIgnoreCase("FIM"));
    }

    public static void encrypt(String input, char[] s) {
        
        for (int i = 0; i < input.length(); i++) {
           

            
                
                s[i] = (char) (input.charAt(i) + 3);
            

            
        }
         System.out.println(new String(s));
    }
}