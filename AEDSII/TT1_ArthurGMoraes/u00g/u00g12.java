import java.util.*;

class u00g12{
    public static Scanner sc = new Scanner(System.in);
    public static void main (String[] args){
        int num = 0;
        int maior = 0;
        int menor = 0;
        int i = 0;

        System.out.print("Insira 10 numeros: ");
        for (i = 0; i < 10; i++){
            num = sc.nextInt();
            if (i == 0){
                menor = num;
            }
            if (num > maior){
                maior = num;
            } else if (num < menor){
                menor = num;
            }
        }
        System.out.print("Maior = " + maior + " e menor = " + menor);
        sc.close();
    }
}