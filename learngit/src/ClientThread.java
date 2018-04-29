import java.io.BufferedReader;
import java.io.IOException;
import java.net.Socket;

public class ClientThread extends Thread {
 BufferedReader br=null;
 public ClientThread(BufferedReader brServer)
 {
	 this.br=brServer;
 }
 public ClientThread(Socket s) {
	// TODO Auto-generated constructor stub
}
public void run()
 {
	 try
	 {
		 String line=null;
		 while((line=br.readLine())!=null)
		 {
			 System.out.println(line);
			 
		 }
	 }
	 catch(IOException ex)
	 {
		 ex.fillInStackTrace();
	 }
	 finally
	 {
		 try
		 {
			 if(br!=null)
			 {
				 br.close();
			 }
		 }
		 catch(IOException ex)
		 {
			 ex.printStackTrace();
		 }
	 }
 }
}
