import java.util.*;

class u00g6{
    public static Scanner sc = new Scanner(System.in);
    public static void main (String[] args){

        int maior = 0;
        int menor = 0;
        int num = 0;

        System.out.println("");
        System.out.print("Informe tres numeros: ");
        for (int i = 0; i < 3 ; i++){
            num = sc.nextInt();
            if ( i == 0){
                menor = num;
            }
            if (num > maior){
                maior = num;
            } else if (num < menor) {
                menor = num;
            }
        }
        System.out.println("Menor = " + menor + " e maior = " + maior);
        sc.close();
    }
}