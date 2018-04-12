import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;

public class server{
	public static void main(String[] args){
	try{
		System.out.println("Listening----");
		ServerSocket ss = new ServerSocket(5549);
		Socket soc = ss.accept();
		System.out.println("Connetion establish");
		BufferedReader in = new BufferedReader(new 
InputStreamReader(soc.getInputStream()));
		String str = in.readLine();
		PrintWriter out = new 
PrintWriter(soc.getOutputStream(),true);
		
		String a = "Assalamualaikum".toLowerCase();
		
		if(str.equals(a))
		{out.println("Waalaikumusalam"); }

		else
		{out.println("Are you muslim");}
	}
	catch(Exception e)
	{ e.printStackTrace();}
 }
}
