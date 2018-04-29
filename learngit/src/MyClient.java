import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

public class MyClient {
  public static void main(String[] args)throws Exception
  {
	  Socket s=new Socket("127.0.01",30000);
	  new Thread(new ClientThread(s)).start();
	  PrintStream ps=new PrintStream(s.getOutputStream());
	  String line =null;
	  BufferedReader br=new BufferedReader(
			  new InputStreamReader(System.in));
	  while ((line=br.readLine())!=null)
	  {
		  ps.println(line);
	  }
  }
}
