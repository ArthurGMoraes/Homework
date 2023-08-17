import java.util.*;

class u00g14 {
    public static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        
        System.out.print("Digite uma palavra: ");
        String palavra = sc.nextLine().toLowerCase(); 
        
        int tamanho = palavra.length();
        int letras = 0;
        int naoLetras = 0;
        int vogais = 0;
        int consoantes = 0;
        
        for (int i = 0; i < tamanho; i++) {
            char caractere = palavra.charAt(i);
            
            if (Character.isLetter(caractere)) {
                letras++;
                if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u') {
                    vogais++;
                } else {
                    consoantes++;
                }
            } else {
                naoLetras++;
            }
        }
        
        System.out.println("Número de caracteres: " + tamanho);
        System.out.println("Número de letras: " + letras);
        System.out.println("Número de não letras: " + naoLetras);
        System.out.println("Número de vogais: " + vogais);
        System.out.println("Número de consoantes: " + consoantes);
        
        sc.close();
    }
}
