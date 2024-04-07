package aeds3;

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
import java.util.List;

public class Arquivo<T extends Registro> {

  protected RandomAccessFile arquivo;
  protected String nomeEntidade = "";
  protected Constructor<T> construtor;
  final protected int TAM_CABECALHO = 4;
  protected HashExtensivel<ParIDEndereco> indiceDireto;
  public RegDeletado indiceDeletado;

  public Arquivo(String na, Constructor<T> c) throws Exception {
    this.nomeEntidade = na;
    this.construtor = c;
    arquivo = new RandomAccessFile("dados/" + na + ".db", "rw");
    if (arquivo.length() < TAM_CABECALHO) {
      arquivo.seek(0);
      arquivo.writeInt(0);
    }
    indiceDireto = new HashExtensivel<>(ParIDEndereco.class.getConstructor(),
        3,
        "dados/" + na + ".hash_d.db",
        "dados/" + na + ".hash_c.db");

        indiceDeletado = new RegDeletado(na + ".lista_d.db");
  }

  public int create(T obj) throws Exception {
    arquivo.seek(0);
    int ultimoID = arquivo.readInt();
    ultimoID++;
    arquivo.seek(0);
    arquivo.writeInt(ultimoID);
    obj.setID(ultimoID);

    if (!indiceDeletado.isEmpty()){
        byte[] ba = obj.toByteArray();
        short tam = (short) ba.length;
        long pos = indiceDeletado.conferir(tam);
        //System.out.println("EMPTY ");
      if(pos>0){
        //System.out.println(pos);
        indiceDeletado.remover(pos);
        indiceDeletado.escreverArq();
        arquivo.seek(pos);
        arquivo.writeByte(' '); // lápide
        arquivo.writeShort(tam);
        arquivo.write(ba);
        indiceDireto.create(new ParIDEndereco(obj.getID(), pos));
        return obj.getID();
      }
    }
      // System.out.println("DIRETO");
      arquivo.seek(arquivo.length());
      long endereco = arquivo.getFilePointer();
      byte[] ba = obj.toByteArray();
      short tam = (short) ba.length;
      arquivo.writeByte(' '); // lápide
      arquivo.writeShort(tam);
      arquivo.write(ba);
      indiceDireto.create(new ParIDEndereco(obj.getID(), endereco));
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
    // else{
    //   throw new Exception("Elemento inexistente");
    // }
    
    return null;
  }


  public boolean delete(int id) throws Exception {
    ParIDEndereco pie = indiceDireto.read(id);
    long endereco = pie != null ? pie.getEndereco() : -1;
    if (endereco != -1) {
      arquivo.seek(endereco);
      arquivo.writeByte('*');
      int tam = arquivo.readShort();
      // System.out.println(endereco + " " + tam + " DELETE");
      indiceDeletado.inserir(endereco, tam);
      indiceDeletado.escreverArq();
      indiceDireto.delete(id);
      
    
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