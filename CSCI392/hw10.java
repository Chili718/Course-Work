/*
//Title: Web Crawler 2.0
//
//Name: Jon Tice
//
//Description: Crawls through the file specified within the webserver to a depth of 1 and 
//prints out all the links names and whether they are external, valid, or broken. 
//Class: CSCI 392
//
//Date: 11/20/2017
*/
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import java.io.*;
import java.net.*;

public class hw10
{

	public static void main(String[] args) throws IOException
   	{		
		
    		//check if the user provided the HTML file
		if(args.length == 0)
		{
			System.out.println("ERROR: user must specify HTML file vie command line. cannot recover. exiting.");
			return;
		}
		//prints all of the links to a depth of one and if they are valid, external, or broken.
		printLinks(args[0], 0);

   	}
	//The function printLinks will take the url provided and print the links inside and whether they are
	//external, valid, or broken then recursively print the links of all the valid links found previously until 
	//a depth of 1 is reached  
	public static void printLinks(String urlP, int level)
	{
		
		Document doc   = null;
                Elements links = null;
                Element  link  = null;
		//creates the document from the function createDoc
		doc = createDoc(urlP);

                //gets all the links from the document created above
                links = doc.select("a[href]");
		//prints the number of links in the document
		if(level == 0)
	        	System.out.println("There are " + links.size() + " links:");
		else
			System.out.printf("%9s%s%s%s%n", "", "There are ", links.size(), " links:");	

		//will go through all of the links in the document created above
                for (int i=0; i<links.size(); i++)
                {
			//get the next link out of links
                        link = links.get(i);
			//if the link is not external it will be checked for validity
			if(isExternal(link.attr("href")))
			{
				//based on the level of depth spaces will be added for a nicer looking output
				if(level == 0)
					System.out.println("external --> " + link.attr("href"));
				else	
					System.out.printf("%9s%s%s%n", "", "external --> ", link.attr("href"));
			}
			else if(isValid(link.attr("href"), urlP))
			{
				//based on the level of depth spaces will be added for a nicer looking output
				if(level == 0)
					System.out.println("okay\t --> " + link.attr("href"));
                                else
					System.out.printf("%9s%s%s%n", "", "okay\t --> ", link.attr("href"));
				//if the link is valid and is a htm or html file the file will be checked 
				//for all links if not at a depth greater than zero
				if(level != 1 && (((link.attr("href")).indexOf(".htm") >= 0 || (link.attr("href")).indexOf(".html") >= 0)))
				{
					printLinks(createLink(link.attr("href"),urlP), level+1);

					level = 0;
				}
				
			}
			else
			{
				//based on the level of depth spaces will be added for a nicer looking output
				if(level == 0)
                                	System.out.println("broken\t --> " + link.attr("href"));
				else
                                	System.out.printf("%9s%s%s%n", "", "broken\t --> ", link.attr("href"));
			}
			
                }


	}
	//The function isExternal is passed the name of the href and returns a boolean value based
	//if the link is external or not
	public static boolean isExternal(String name)
	{
		//the link is external if it contains http:// or https://
		if(name.indexOf("http://") >= 0 || name.indexOf("https://") >= 0)
			return true;
		else
			return false;
	}
	//The function isValid is passed the name of the href that will be valid or not and
	//the root name link initially given by the user 
	public static boolean isValid(String nme, String urlP2)
	{
		String outmsg = createLink(nme, urlP2);
		String inputline = "";
		
		//combining it all to create the out message
		outmsg = "GET " + outmsg + " HTTP/1.0\r\n\r\n";

		//System.out.println(outmsg);

		//use javas networking functions to get the file and read the first line
		try
		{
			Socket sock = new Socket ("faculty.winthrop.edu",80);

			InputStream sin = sock.getInputStream();
       			BufferedReader fromServer = new BufferedReader(new InputStreamReader(sin));
			OutputStream sout = sock.getOutputStream();
	       		PrintWriter toServer = new PrintWriter (new OutputStreamWriter(sout));

			toServer.print (outmsg);
       			toServer.flush();

			inputline = fromServer.readLine();
		}
		catch(Exception e)
		{
			System.out.println(e.getMessage());
		}
		
		//if the file is valid the first line should contain 200
		if(inputline.indexOf("200") >= 0)
			return true;
		else
			return false;
	}
	//The createDoc function creates a document variable from the url string passed
	public static Document createDoc(String createURL)
	{
		Document docu = null;

		//removing the / at the begining of the string if the user enetered something like
		//"/dannellys" the  '/' will be appended below
		if(createURL.indexOf('/') == 0)
			createURL = createURL.substring(1, createURL.length());

		// did it include http:// at the beginning?
                if(createURL.indexOf("http://faculty.winthrop.edu/") != 0 )
                        createURL = "http://faculty.winthrop.edu/" + createURL;

		//should it fail to connect it will return docu with the default null value
                try
                {
                        docu = Jsoup.connect(createURL).get();
                }
                catch (Exception e)
                {
                        System.out.println("Error: Unable to get that URL.");
                }

		return docu;

	}	
	//The createLink function creates the link from the href title(file) and the directory (inputUrl)
	public static String createLink(String file, String inputUrl)
	{
		//removing the default.htm to append the link we want to check
                if(inputUrl.indexOf("default.htm") >= 0)
                        inputUrl = inputUrl.substring(0, inputUrl.indexOf("default.htm"));
                //adding /'s where needed
                if(inputUrl.indexOf('/') != 0 )
                        inputUrl = "/" + inputUrl;

                if(inputUrl.lastIndexOf('/') != inputUrl.length()-1)
                        inputUrl = inputUrl + "/";
		
		//removing the '../' that comes with using the jsoup functions
		if(file.indexOf("../") >= 0)
			file = file.substring(3, file.length());

		inputUrl = inputUrl + file;

		return inputUrl;

	}

}


