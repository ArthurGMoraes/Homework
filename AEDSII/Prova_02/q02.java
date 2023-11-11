import java.util.*;

class q02{
    public static MyIO sc = new MyIO();

    public static void ordenar(String[] array){
        String tmp;

        for (int i = 0; i < array.length - 1; i++){
            if (array[i] != null){
                if(array[i+1].length() > array[i].length()){

                    for (int j = i+1; j > 0; j--){
                        if (array[j].length()> array[j-1].length()){
                            //printf("if2\n");
                            tmp = array[j-1];
                            array[j-1] = array[j];
                            array[j] = tmp;
                        }   
                    }   
                }   
            }
        }

        for (int i = 0; i < array.length; i++){
            if (array[i] != null){
                sc.print(array[i] + " ");
            }
        }
        sc.print("\n");
    }

    public static void main(String[] args){
        
        int quantidade = 0;
        String[] array = new String[50];
        String teste;

        quantidade = sc.readInt();

        for(int i = 0; i < quantidade; i++){
           teste = sc.readLine();
           array = teste.split(teste, 50); // nao consegui pensar em uma formade saparar as strings da linha, alem disso acho que o a ordenacao funciona
           ordenar(array);
        }
        
    }
}