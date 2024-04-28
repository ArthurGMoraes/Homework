package aed3;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.RandomAccessFile;
import java.lang.reflect.Constructor;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Arquivo<T extends Registro> {

  protected RandomAccessFile arquivo;
  protected String nomeEntidade = "";
  protected Constructor<T> construtor;
  final protected int TAM_CABECALHO = 4;
  protected HashExtensivel<ParIDEndereco> indiceDireto;
  protected ListaInvertida listaInvertida;

  public Arquivo(String na, Constructor<T> c) throws Exception {
    this.nomeEntidade = na;
    this.construtor = c;
    listaInvertida = new ListaInvertida(4, "dados/dicionario.listainv.db", "dados/blocos.listainv.db");
    arquivo = new RandomAccessFile("dados/" + na + ".db", "rw");
    if (arquivo.length() < TAM_CABECALHO) {
      arquivo.seek(0);
      arquivo.writeInt(0);
    }
    indiceDireto = new HashExtensivel<>(ParIDEndereco.class.getConstructor(),
        3,
        "dados/" + na + ".hash_d.db",
        "dados/" + na + ".hash_c.db");
  }

  public int create(T obj) throws Exception {
    arquivo.seek(0);
    int ultimoID = arquivo.readInt();
    ultimoID++;
    arquivo.seek(0);
    arquivo.writeInt(ultimoID);
    obj.setID(ultimoID);

    arquivo.seek(arquivo.length());
    long endereco = arquivo.getFilePointer();
    byte[] ba = obj.toByteArray();
    short tam = (short) ba.length;
    arquivo.writeByte(' '); // lápide
    arquivo.writeShort(tam);
    arquivo.write(ba);
    indiceDireto.create(new ParIDEndereco(obj.getID(), endereco));
    String[] tituloArray = obj.getTitulo().split(" ");
    for (int i = 0; i < tituloArray.length; i++){
      listaInvertida.create(tituloArray[i].toLowerCase(), obj.getID());
    }
    listaInvertida.print();
    return obj.getID();
  }

  public T read(int id) throws Exception {
    T obj = construtor.newInstance();
    short tam;
    byte[] ba;

    ParIDEndereco pie = indiceDireto.read(id);
    long endereco = pie != null ? pie.getEndereco() : -1;
    if (endereco != -1) {
      arquivo.seek(endereco + 1); // pula o lápide também
      tam = arquivo.readShort();
      ba = new byte[tam];
      arquivo.read(ba);
      obj.fromByteArray(ba);
      return obj;
    }
    return null;
  }

  public void buscar(String s) throws Exception{
    String[] palavras = s.split(" ");
    ArrayList<int[]> ids = new ArrayList<>();
    for (int i = 0; i < palavras.length; i++){
        ids.add(listaInvertida.read(palavras[i].toLowerCase()));
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
    
    // Convert ArrayList to array
    Integer[] resultArray = commonNumbers.toArray(new Integer[0]);
        for (int i = 0; i < resultArray.length; i++){
          System.out.println(read(resultArray[i]));
        }
  }
        

  public boolean delete(int id) throws Exception {
    T obj = construtor.newInstance();
    short tam;
    byte[] ba;
    ParIDEndereco pie = indiceDireto.read(id);
    long endereco = pie != null ? pie.getEndereco() : -1;
    if (endereco != -1) {
      arquivo.seek(endereco);
      arquivo.writeByte('*');
      indiceDireto.delete(id);
      tam = arquivo.readShort();
      ba = new byte[tam];
      arquivo.read(ba);
      obj.fromByteArray(ba);
      String[] tituloArray = obj.getTitulo().toLowerCase().split(" ");
      for (int i = 0; i < tituloArray.length; i++){
        listaInvertida.delete(tituloArray[i], obj.getID());
      }
      listaInvertida.print();
      return true;
    } else
      return false;
  }

  public boolean update(T novoObj) throws Exception {
    T obj = construtor.newInstance();
    short tam, tam2;
    byte[] ba, ba2;
    ParIDEndereco pie = indiceDireto.read(novoObj.getID());
    long endereco = pie != null ? pie.getEndereco() : -1;

    if (endereco != -1) {
      arquivo.seek(endereco + 1); // pula o campo lápide
      tam = arquivo.readShort();
      ba = new byte[tam];
      arquivo.read(ba);
      obj.fromByteArray(ba);
      ba2 = novoObj.toByteArray();
      tam2 = (short) ba2.length;
      if (tam2 <= tam) {
        arquivo.seek(endereco + 1 + 2);
        arquivo.write(ba2);
      } else {
        arquivo.seek(endereco);
        arquivo.writeByte('*');
        arquivo.seek(arquivo.length());
        long endereco2 = arquivo.getFilePointer();
        arquivo.writeByte(' ');
        arquivo.writeShort(tam2);
        arquivo.write(ba2);
        indiceDireto.update(new ParIDEndereco(novoObj.getID(), endereco2));
      }
      return true;
    }
    return false;
  }

  public void close() throws Exception {
    arquivo.close();
    indiceDireto.close();
  }

}