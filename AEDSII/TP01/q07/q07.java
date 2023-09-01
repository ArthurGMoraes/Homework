class q07{
    public static void main(String[] args){
        MyIO myIo = new MyIO();
        String palavra = "";
        do{
            palavra = myIo.readLine();
            if (!palavra.equalsIgnoreCase("FIM")){
               
                myIo.println( x1 + " " + x2  + " " + x3 + " " + x4);  // saida dos resultados formatados
            }
        } while (!palavra.equalsIgnoreCase("FIM"));             // Loop para executar as funcoes enquanto palavra != FIM
    }
}