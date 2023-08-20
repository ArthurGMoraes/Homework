import java.util.*;

class u00g8{
    public static Scanner sc = new Scanner(System.in);
    public static void main (String[] args){
        int num1 = 0;
        int num2 = 0;
        int result = 0;
        System.out.print("Primeiro numero: ");
        num1 = sc.nextInt();
        System.out.print("Segundo numero: ");
        num2 = sc.nextInt();
        if (num1 > 45 || num2 > 45){
            result = num1 + num2;
            System.out.print(result);
        } else if (num1 > 20 && num2 > 20){
            if (num1 > num2){
                result = num1 - num2;
            } else {
                result = num2 - num1;
            }
            System.out.print(result);
        } else if ((num1 < 10 || num2 > 10) && (num1 != 0 && num2 != 0)){
            result = num1 / num2;
            System.out.print(result);
        } else {
            System.out.print("Arthur");
        }
        sc.close();
    }
}