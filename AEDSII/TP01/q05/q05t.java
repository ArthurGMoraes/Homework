import java.lang.reflect.Method;
class q05t{ 
    public static void DemoTest {
   private void sampleMethod(){
      System.out.println("hello");
   }
}
public static void main (String[] args) {
   public static void main(String args[]) throws Exception{
      Class c = Class.forName("DemoTest");
      Object obj = c.newInstance();
      
      Method method = c.getDeclaredMethod("sampleMethod", null);
      method.setAccessible(true);
      method.invoke(obj, null);
   }
}
}

