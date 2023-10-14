class teste{
    public static void ler(int num){
        Arq.openRead("/tmp/players.csv");
        int i = 0;
        String str = "";
        MyIO.println(num);
        while(i < num + 1){
            Arq.readLine();
            i++;
        }
        str = Arq.readLine();
        MyIO.println(i +" "+ str);
        str += " ";
        String[] parts = str.split(",");
        for (int k = 0; k < parts.length; k++) {
            if (parts[k].isEmpty() || parts[k].equals(" ")) {
                parts[k] = "nao informado";
            }
        } 
        int id = Integer.parseInt(parts[0]);
        String nome = parts[1];
        int altura = Integer.parseInt(parts[2]);
        int peso = Integer.parseInt(parts[3]);
        String cidadeNascimento = parts[6];
        String estadoNascimento = parts[7];
        int anoNascimento = Integer.parseInt(parts[5]);
        String universidade = parts[4];
        MyIO.println("[" + id + " ## " + nome + " ## " + altura + " ## " + peso + " ## " + anoNascimento + " ## " + universidade + " ## " + cidadeNascimento + " ## " + estadoNascimento.trim() + "]");
        Arq.close();
    }

    public static void main(String[] args){
        for (int i = -2; i < 3000; i++){
            ler(i);
        }
    }

}