import java.util.*;

class u00g7{
    public static Scanner sc = new Scanner(System.in);
    public static void main (String[] args){
        int num = 0;
        int maior = 0;
        int i = 0;

        System.out.print("Insira 10 numeros: ");
        for (i = 0; i < 10; i++){
            num = sc.nextInt();
            if (num > maior){
                maior = num;
            }
        }
        System.out.print("Maior = " + maior);
        sc.close();
    }
}