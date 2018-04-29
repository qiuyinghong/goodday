import java.awt.List;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Collections;

public class MyServer {
  public static List socketList1
  =(List) Collections.synchronizedList(new ArrayList<>());
public static Object socketList;
  @SuppressWarnings("unchecked")
public static void main(String[] args)
  throws IOException
  {
	  @SuppressWarnings("resource")
	ServerSocket ss=new ServerSocket(30000);
	  while(true)
	  {
		  Socket s=ss.accept();
		  ((ArrayList<Object>) socketList).add(s);
		  new Thread(new ServerThread(s)).start();
	  }
  }
}
