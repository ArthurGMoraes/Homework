import java.util.*;

class u00g4 {
    public static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.print("Qual é a nota: ");
        double nota = scanner.nextDouble();
        if (nota>=80.0){
            System.out.print("Muito bom");
        } else if (nota>=70 && nota<80){
            System.out.print("Aprovado");
        } else {
            System.out.print("Reprovado");
        }
        scanner.close();
    }
}