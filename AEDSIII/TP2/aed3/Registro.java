package aed3;

public interface Registro extends Comparable<Object>, Cloneable {

  public int getID();

  public String getTitulo();

  public void setID(int id);

  public byte[] toByteArray() throws Exception;

  public void fromByteArray(byte[] ba) throws Exception;

  public int compareTo(Object b);

  public String toString();

  public Object clone() throws CloneNotSupportedException;
}
