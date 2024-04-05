import java.io.*;
import aeds3.Arquivo;

class Principal {

  public static void main(String args[]) {

    new File("dados/livros.db").delete();
    new File("dados/livros.hash_d.db").delete();
    new File("dados/livros.hash_c.db").delete();
    new File("dados/livros.hashDelete_d.db").delete();
    new File("dados/livros.hashDelete_c.db").delete();

    Arquivo<Livro> arqLivros;
    Livro l1 = new Livro(-1, "9788563560278", "Odisseia", 15.99F);
    Livro l2 = new Livro(-1, "9788584290482", "Ensino Híbrido", 39.90F);
    Livro l3 = new Livro(-1, "9786559790005", "Modernidade Líquida", 48.1F);
    Livro l4 = new Livro(-1, "9788582714911", "Memória", 55.58F);
    Livro l5 = new Livro(-1, "9786587150062", "Com Amor", 48.9F);
    int id1, id2, id3, id4, id5;

    try {
      arqLivros = new Arquivo<>("livros", Livro.class.getConstructor());

      id1 = arqLivros.create(l2);
      
      id2 = arqLivros.create(l2);

      arqLivros.delete(id1);

      id3 = arqLivros.create(l1);



      System.out.println("\nLivro 1:\n" + arqLivros.read(1));
      System.out.println("\nLivro 2:\n" + arqLivros.read(2));
      System.out.println("\nLivro 3:\n" + arqLivros.read(3));
      

      arqLivros.close();

    } catch (Exception e) {
      e.printStackTrace();
    }

  }

}