import java.util.*;

class u00g5{
    public static Scanner sc = new Scanner(System.in);
    public static void main (String[] args){
        System.out.print("Informe os lados do triangulo: ");
        double lado1 = sc.nextDouble();
        double lado2 = sc.nextDouble();
        double lado3 = sc.nextDouble();
        if (lado1 == lado2 && lado1 == lado3){
            System.out.print("Equilatero");
        } else if ((lado1 == lado2 && lado1 != lado3) || (lado1 == lado3 && lado1 != lado2) || (lado2 == lado3 && lado2 != lado1)){
            System.out.print("Isoceles");
        } else {
            System.out.print("Escaleno");
        }
        sc.close();
    }
}