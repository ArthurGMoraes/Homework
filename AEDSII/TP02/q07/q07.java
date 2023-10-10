class q07{
    public static void main(String[] args){
        Arq arq = new Arq();
        arq.openRead("/tmp/players.csv");
        MyIO.println(arq.readAll());
        MyIO.println("teste");
    }
}