import java.util.*;

class u00g9{
    public static Scanner sc = new Scanner(System.in);
    public static void main (String[] args){
        int time1 = 0;
        int time2 = 0;
        System.out.print("Primeiro time: ");
        time1 = sc.nextInt();
        System.out.print("Segundo time: ");
        time2 = sc.nextInt();
        if (time1 > time2){
            System.out.print("Time 1 ganhou");
        } else if (time2 > time1){
            System.out.print("Time 2 ganhou");
        } else {
            System.out.print("Empate");
        }
        sc.close();
    }
}