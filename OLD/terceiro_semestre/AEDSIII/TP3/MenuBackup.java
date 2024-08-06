import java.io.File;
import java.io.RandomAccessFile;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

import aeds3.LZW;

public class MenuBackup {
    Path directoryPath;
    private static Scanner console = new Scanner(System.in);

    public MenuBackup() throws Exception{
        directoryPath = Files.createDirectories(Paths.get("backup"));
    }
    public void menu(){
        int opcao;
        do {
            System.out.println("\n\n\nBOOKAEDS 1.0");
            System.out.println("------------");
            System.out.println("\n> Início > Backup");
            System.out.println("\n1) Fazer Backup");
            System.out.println("2) Escolher Backup");
            System.out.println("\n0) Retornar ao menu anterior");

            System.out.print("\nOpção: ");
            try {
                opcao = Integer.valueOf(console.nextLine());
            } catch (NumberFormatException e) {
                opcao = -1;
            }

            // Seleciona a operação
            switch (opcao) {
                case 1:
                    fazBackup();
                    break;
                case 2:
                    voltaBackup();
                    break;
                case 0:
                    break;
                default:
                    System.out.println("Opção inválida");
                }
        } while (opcao != 0);
    }

    private int versao = 1;
    public void fazBackup(){
        RandomAccessFile arq;
        RandomAccessFile arq2;
        Path directoryPath2;
        byte[] ba;
        byte[] msgCod;
        int ori = 0;
        int cod = 0;

        try{
            RandomAccessFile tmp = new RandomAccessFile("backup/versao.txt", "rw");
            if(tmp.length()>0){              // confere a versão a ser utilizada para o próximo backup;
                versao = tmp.readInt();
            } else {
                tmp.writeInt(versao);
            }                                          
            File folder = new File("dados");   
            File[] listOfFiles = folder.listFiles();            // array contendo todos os arquivos do diretório dados
            if(listOfFiles != null) {
                directoryPath2 = directoryPath.resolve("v" + Integer.toString(versao) );   //cria diretório para essa versão do backup
                Files.createDirectories(directoryPath2);
                for (int i = 0; i < listOfFiles.length; i++) {      // compacta cada arquivo e escreve no diretório
                    arq = new RandomAccessFile("dados/" + listOfFiles[i].getName(), "r");
                    //ori = ori + (int)arq.length();
                    ba = new byte[(int)arq.length()];
                    arq.read(ba);
                    msgCod = LZW.codifica(ba);
                    arq2 = new RandomAccessFile("backup/v" + Integer.toString(versao) + "/" + listOfFiles[i].getName() , "rw" );
                    arq2.write(msgCod);
                    //cod = cod + (int)arq2.length();
                    arq.close();
                    arq2.close();
                }           
                //System.out.println((float)cod/ori);    
                versao++;
                tmp.seek(0);
                tmp.writeInt(versao); // atualiza versão
                tmp.close();
            }
        } catch (Exception e){
            e.printStackTrace();
        }
    }

    public void voltaBackup(){
        byte[] ba;
        byte[] msgDecod;
        RandomAccessFile arq;
        RandomAccessFile arq2;
        int i = 0;
        try{
            File folder = new File("backup");
            File[] listOfFiles = folder.listFiles();            // array contendo todos os backups
            
            if (listOfFiles.length > 0){                        // Menu para selecionar versão a ser restaurada
                System.out.println("Selecione a versão do backup: ");
                for  (i= 1; i < listOfFiles.length+1; i++) {
                    if(!listOfFiles[i-1].getName().equals("versao.txt")){
                        System.out.println(i + ") " + listOfFiles[i-1].getName());
                    }
                }
            } else {
                System.out.println("Nenhum backup disponível");
            }
            System.out.println("\n0) Retornar ao menu anterior");
            System.out.print("\nOpção: ");
            int opcao = Integer.valueOf(console.nextLine());
            if (!(opcao> 0 && opcao<=i)){
                if(opcao==0){
                    return;
                } 
                System.out.println("Backup inválido");
                return;
            }                                                   // Menu para selecionar versão a ser restaurada
            folder = new File("backup/v" + opcao);
            listOfFiles = folder.listFiles();
            if (listOfFiles != null){
                for (i = 0; i < listOfFiles.length; i++) {                      //decodifica cada arquivo e sobrescreve no diretório de dados
                    //System.out.println(listOfFiles[i].getName());
                    arq = new RandomAccessFile("backup/v"+opcao+"/" + listOfFiles[i].getName(), "r");
                    
                    ba = new byte[(int)arq.length()];
                    arq.read(ba);
                    //System.out.println(ba.length);
                    msgDecod = LZW.decodifica(ba);
                    new File("dados/"+listOfFiles[i].getName()).delete();
                    arq2 = new RandomAccessFile("dados/"+listOfFiles[i].getName(), "rwd");
                    arq2.write(msgDecod);
                    arq2.close();
                }
            }
            
        } catch (Exception e){
            e.printStackTrace();
        }
        
    }
}

