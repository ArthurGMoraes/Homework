class teste{
    public static void main(String[] args){
        Arq.openRead("/tmp/players.csv");
        MyIO.println(Arq.readLine());
        MyIO.println(Arq.readLine());
        MyIO.println(Arq.readLine());
        MyIO.println(Arq.readLine());
        Arq.close();
    }
}