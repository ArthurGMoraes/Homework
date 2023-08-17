import java.util.Scanner;

class u00g2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Int: ");
        int inteiro = scanner.nextInt();

        System.out.print("Double: ");
        double real = scanner.nextDouble();
        scanner.nextLine(); 

        System.out.print("String: ");
        String string = scanner.nextLine();

        System.out.println("Inteiro: " + inteiro);
        System.out.println("Real: " + real);
        System.out.println("String: " + string);

        scanner.close();
    }
}