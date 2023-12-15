import java.util.*;

class u00g10{
    public static Scanner sc = new Scanner(System.in);
    public static void main (String[] args){
        int salario = 0;
        int prestacao = 0;
        System.out.print("Salario: ");
        salario = sc.nextInt();
        System.out.print("Prestacao: ");
        prestacao = sc.nextInt();
        if (prestacao < salario * 0.4){
            System.out.print("Emprestimo concedido");
        } else {
            System.out.print("Emprestimo negado");
        }
        sc.close();
    }
}