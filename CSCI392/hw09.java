/*
//Title: Web Crawler 1.0
//
//Name: Jon Tice
//
//Description: Crawls through the file specified within the webserver hardcoded and 
//prints out all the links names bad or good. 
//Class: CSCI 392
//
//Date: 10/26/2017
*/
import java.net.*;
import java.io.*;
public class hw09 
{
   	public static void main(String[] args)
	{
		if (args.length == 0)
     		{
       			System.out.println("please specify the file to retrieve, exiting...\n\n");
       			return;
     		} 

     		try
     		{
       			// connect to the server
   			Socket sock = new Socket ("faculty.winthrop.edu",80);

  			// get the reading and writing streams
      			InputStream sin = sock.getInputStream();
       			BufferedReader fromServer = new BufferedReader(new InputStreamReader(sin));
       			OutputStream sout = sock.getOutputStream();
       			PrintWriter toServer = new PrintWriter (new OutputStreamWriter(sout));

			// build the request message (/dannellys/default.htm)
       			String outmsg = "GET ";
       			outmsg += args[0];
       			outmsg += " HTTP/1.0\r\n\r\n";
			
       			// send the request to the server
       			toServer.print (outmsg);
       			toServer.flush();

       			// read the response line by line, and echo to stdout
       			String inputline = fromServer.readLine();
       			while (inputline != null)
       			{
				//checking if the string will contain a link
				if(inputline.indexOf("<a") >= 0 && inputline.indexOf("a>") > 0 && inputline.indexOf("href") > 0)
				{
					//cutting the string down until just the link names are only whats left
         				inputline = inputline.substring(inputline.indexOf("<a"), inputline.lastIndexOf("a>"));

					inputline = inputline.substring(inputline.indexOf('"')+1, inputline.lastIndexOf('"'));

					while(inputline.lastIndexOf('"')>0)
						inputline = inputline.substring(0, inputline.lastIndexOf('"'));

					System.out.println(inputline);
				}
				//read the next line
       				inputline = fromServer.readLine();
       			} 
     		}
     		catch (Exception e)
     		{
     			System.out.println(e.getMessage());
     		}
   
	}
}
