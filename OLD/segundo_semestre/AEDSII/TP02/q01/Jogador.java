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

     public Jogador (int id){
        this.id = id;
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

    public void ler(){
        MyIO myIo = new MyIO();
        Arq arq = new Arq();
        int i = 0;
        String str = "";
        arq.openRead("/tmp/players.csv");
        while(i < this.id + 1){
                    arq.readLine();
                    i++;
                }
                str = arq.readLine();
                str += " ";
                String[] parts = str.split(",");
                for (int k = 0; k < parts.length; k++) {
                    if (parts[k].isEmpty() || parts[k].equals(" ")) {
                        parts[k] = "nao informado";
                    }
                }
                arq.close();
                setInfos(parts[1], Integer.parseInt(parts[2]), Integer.parseInt(parts[3]), parts[4], Integer.parseInt(parts[5]), parts[6], parts[7]);
    }

    public void setInfos(String nome, int altura, int peso, String universidade, int anoNascimento, String cidadeNascimento, String estadoNascimento){
        this.nome = nome;
        this.altura = altura;
        this.peso = peso;
        this.universidade = universidade;
        this.anoNascimento = anoNascimento;
        this.cidadeNascimento = cidadeNascimento;
        this.estadoNascimento = estadoNascimento;
    }

    

    public static void main(String[] args){
        MyIO myIo = new MyIO();
        Arq arq = new Arq();
        String id = "";
        int i = 0;

        while (!id.equals("FIM")){
            id = myIo.readString();
            if (!id.equals("FIM")){
                Jogador jogador = new Jogador(Integer.parseInt(id));
                jogador.ler();
                jogador.imprimir();
            }
        }
    }
}