import java.util.*;

class Jogador{
    private int id;
    private String nome;
    private int altura;
    private int peso;
    private String universidade;
    private int anoNascimento;
    private String cidadeNascimento;
    private String estadoNascimento;

     public Jogador (){
        this.id = 0;
    }

    public Jogador (int id, String nome, int altura, int peso, String universidade, int anoNascimento, String cidadeNascimento, String estadoNascimento){
        this.id = id;
        this.nome = nome;
        this.altura = altura;
        this.peso = peso;
        this.universidade = universidade;
        this.anoNascimento = anoNascimento;
        this.cidadeNascimento = cidadeNascimento;
        this.estadoNascimento = estadoNascimento;
    }

    public void imprimir(){
        System.out.println("[" + id + " ## " + nome + " ## " + altura + " ## " + peso + " ## " + anoNascimento + " ## " + universidade + " ## " + cidadeNascimento + " ## " + estadoNascimento.trim() + "]");
    }

    

    public static void main(String[] args){
        MyIO myIo = new MyIO();
        Arq arq = new Arq();
        String id = "";
        int i = 0;
        String str = "";

        arq.openRead("/tmp/players.csv");

        while (!id.equals("FIM")){
            arq.openRead("/tmp/players.csv");
            id = myIo.readString();
            i = 0;
            if (!id.equals("FIM")){
                while(i < Integer.parseInt(id) +1){
                    arq.readLine();
                    i++;
                }
                str = arq.readLine();
                str += " ";
                String[] parts = str.split(",");
                for (int k = 0; k < parts.length; k++) {
                    if (parts[k].isEmpty()) {
                        parts[k] = "nao informado";
                    }
                }
                //System.out.println(str);
                //System.out.println(parts.length);

                /*for (String part : parts) {
                    System.out.print(part + " ");
                }
                 System.out.println("");*/

                Jogador jogador = new Jogador(Integer.parseInt(parts[0]), parts[1], Integer.parseInt(parts[2]), Integer.parseInt(parts[3]), parts[4], Integer.parseInt(parts[5]), parts[6], parts[7]);
                jogador.imprimir();
            }
            arq.close();
        }
        
    }
}