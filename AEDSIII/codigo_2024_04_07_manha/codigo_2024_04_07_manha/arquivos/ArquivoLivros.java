package arquivos;

import aeds3.ListaInvertida;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.text.Normalizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import aeds3.Arquivo;
import aeds3.ArvoreBMais;
import aeds3.HashExtensivel;
import aeds3.ParIntInt;
import entidades.Livro;

public class ArquivoLivros extends Arquivo<Livro> {

  HashExtensivel<ParIsbnId> indiceIndiretoISBN;
  ArvoreBMais<ParIntInt> relLivrosDaCategoria;
  protected ListaInvertida listaInvertida;
  private static final String resourceFilePath = "dados/stopwords.txt";
  private List<String> stopwords;

  public ArquivoLivros() throws Exception {
    super("livros", Livro.class.getConstructor());
    indiceIndiretoISBN = new HashExtensivel<>(
        ParIsbnId.class.getConstructor(),
        4,
        "dados/livros_isbn.hash_d.db",
        "dados/livros_isbn.hash_c.db");
    relLivrosDaCategoria = new ArvoreBMais<>(ParIntInt.class.getConstructor(), 4, "dados/livros_categorias.btree.db");
    listaInvertida = new ListaInvertida(4, "dados/dicionario.listainv.db", "dados/blocos.listainv.db");
    stopwords = getFileContentAsList(resourceFilePath);
  }

  @Override
  public int create(Livro obj) throws Exception {
    int id = super.create(obj);
    obj.setID(id);
    indiceIndiretoISBN.create(new ParIsbnId(obj.getIsbn(), obj.getID()));
    relLivrosDaCategoria.create(new ParIntInt(obj.getIdCategoria(), obj.getID()));
    List<String> tituloArray = removeStopWords(obj.getTitulo());
    for (String s : tituloArray){
      
      listaInvertida.create(s, obj.getID());
    }
    listaInvertida.print();
    return id;
  }

  public Livro readISBN(String isbn) throws Exception {
    ParIsbnId pii = indiceIndiretoISBN.read(ParIsbnId.hashIsbn(isbn));
    if (pii == null)
      return null;
    int id = pii.getId();
    return super.read(id);
  }

  @Override
  public boolean delete(int id) throws Exception {
    Livro obj = super.read(id);
    if (obj != null)
      if (indiceIndiretoISBN.delete(ParIsbnId.hashIsbn(obj.getIsbn()))
          &&
          relLivrosDaCategoria.delete(new ParIntInt(obj.getIdCategoria(), obj.getID()))){
            List<String> tituloArray = removeStopWords(obj.getTitulo());
            for (String s : tituloArray){
              listaInvertida.delete(s, obj.getID());
            }
            return super.delete(id);
          }
        
    return false;
  }

  @Override
  public boolean update(Livro novoLivro) throws Exception {
    Livro livroAntigo = super.read(novoLivro.getID());
    if (livroAntigo != null) {

      // Testa alteração do ISBN
      if (livroAntigo.getIsbn().compareTo(novoLivro.getIsbn()) != 0) {
        indiceIndiretoISBN.delete(ParIsbnId.hashIsbn(livroAntigo.getIsbn()));
        indiceIndiretoISBN.create(new ParIsbnId(novoLivro.getIsbn(), novoLivro.getID()));
      }

      // Testa alteração da categoria
      if (livroAntigo.getIdCategoria() != novoLivro.getIdCategoria()) {
        relLivrosDaCategoria.delete(new ParIntInt(livroAntigo.getIdCategoria(), livroAntigo.getID()));
        relLivrosDaCategoria.create(new ParIntInt(novoLivro.getIdCategoria(), novoLivro.getID()));
      }

      // Atualiza o livro
      return super.update(novoLivro);
    }
    return false;
  }

  public void buscar(String s) throws Exception{
    List<String> palavras = removeStopWords(s);
    ArrayList<int[]> ids = new ArrayList<>();
    
    for (String i : palavras){
      ids.add(listaInvertida.read(i));
    }

    // Initialize an array to store the count of occurrences for each number
    int[] occurrences = new int[300];
        
    // Iterate over each array in the ArrayList
    for (int[] array : ids) {
        // Mark the numbers present in the current array
        for (int number : array) {
            occurrences[number]++;
        }
    }
    
    // ArrayList to store numbers that appear in all arrays
    ArrayList<Integer> commonNumbers = new ArrayList<>();
    
    // Iterate over the occurrences array to find numbers that appear in all arrays
    for (int i = 0; i < occurrences.length; i++) {
      if (occurrences[i] == ids.size()) {
        commonNumbers.add(i);
      }
    }
    
    for (int i : commonNumbers){
      System.out.println(read(i));
    }
  }

  private List<String> getFileContentAsList(String resourceFilePath) throws IOException {

    File file = new File(resourceFilePath);
    
    List<String> lines = Files.readAllLines(file.toPath());
    lines = lines.stream().map(line -> Normalizer.normalize(line.toLowerCase().trim(), Normalizer.Form.NFD).replaceAll("[^\\p{ASCII}]", "")).collect(Collectors.toList());
    
    //System.out.println(lines);
    return lines;
  }


  private List<String> removeStopWords(String s) {
    s = s.toLowerCase();
    s = Normalizer.normalize(s, Normalizer.Form.NFD).replaceAll("[^\\p{ASCII}]", "");

    List<String> arrayS = new ArrayList<>(Arrays.asList(s.split(" ")));
    System.out.println(stopwords);
    arrayS.removeAll(stopwords);
    System.out.println(arrayS);

    return arrayS;
  }
}
