// Arthur Goncalves de Moraes

class q01{


    public static void main(String[] args){
        int instancias = 0;
        int m, n = 0;
        String[] portugues;
        String[] japones;
        String  musica;

        instancias = MyIO.readInt();
        for(int i = 0; i < instancias; i++){
            m = MyIO.readInt();
            n = MyIO.readInt();
            portugues = new String[m];
            japones = new String[m];
            for(int j = 0; j < m; j++){
                japones[j] = MyIO.readLine();
                portugues[j] = MyIO.readLine();
            }

            for(int k = 0; k < n; k++){
                musica = MyIO.readLine();
                String[] musicaPalavra = musica.split(" ");
                for(int l = 0; l < musicaPalavra.length; l++){
                    int p = 0;
                    for (p = 0; p < m; p++){
                        if (musicaPalavra[l].trim().equals(japones[p].trim())){    
                            MyIO.print(portugues[p] + " ");
                            p = m+1;
                        } 
                    }
                    if (p == m){
                        MyIO.print(musicaPalavra[l] + " ");
                    }
                }
                MyIO.println(" ");
            }
            MyIO.println(" ");
        }   
    }
}

