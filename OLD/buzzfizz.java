// fizzbuss with ternary operators
import java.util.*;

class buzzfizz {
    public static void bf (int n){
        for (int i = 1; i <= n; i++){
            String resp = (((i%3 == 0)?"FIZZ":"") + ((i%5 == 0)?"BUZZ":"") + ((i%7==0)?"BASS":""));
            System.out.println(resp.isEmpty()?i:resp);
        }
    }
    public static void main (String Args[]){
        if(Args.length > 0)
            bf(Integer.parseInt(Args[0]));
        else 
            bf(100);
    }
}