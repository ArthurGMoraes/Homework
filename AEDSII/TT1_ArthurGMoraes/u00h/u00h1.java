import java.util.*;

class u00h1 {
    public static Scanner sc = new Scanner(System.in);
    public static int notLetra (String palavra, int posicao){
        int total = 0;
        int tamanho = palavra.length();
        char caractere;

        if (posicao >= tamanho){
            return 0;
        }
        
        caractere = palavra.charAt(posicao);
        if (!Character.isLetter(caractere)) {
            total = 1; 
        }
        
        return total + notLetra(palavra, posicao + 1);
    }

    public static void main(String[] args) {
        System.out.print("Digite uma palavra: ");
        String palavra = sc.nextLine().toLowerCase();
        System.out.println(notLetra(palavra, 0));
        sc.close();
    }
}
