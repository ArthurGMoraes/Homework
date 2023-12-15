import java.util.*;
import java.lang.Math.*;

class u00g11{
    public static Scanner sc = new Scanner(System.in);
    public static double logb(double num, double base) {
    double result = (Math.log(num) / Math.log(base));
    return result;
    }
    public static void main (String[] args){
        double num1 = 0;
        double num2 = 0;
        double result1 = 0;
        double result2 = 0;
        System.out.print("Num1: ");
        num1 = sc.nextDouble();
        System.out.print("Num2: ");
        num2 = sc.nextDouble();
        if (num1 > num2){
            result1 = Math.pow(num2, 3.0);
            System.out.print(result1 + " " + logb(num2, num1));
        } else {
            result1 = Math.pow(num1, 3.0);
            System.out.print(result1 + " " + logb(num1, num2));
        }
        sc.close();
    }
}