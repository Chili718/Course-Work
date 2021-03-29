/*
//Title: hw05_test.java
//
//Name: Jon Tice
//
//Description:Test "main" for the histogram class
//
//Class:CSCI392
//
//Date:9/23/2017
*/
import java.io.*;
public class hw05_test
{
	public static void main(String[] args) throws IOException
	{
		
		String fileNme, dataLine;//name of file and the data line from the file
		BufferedReader inputFile, countFile;//file buffers
		int lineCount = 0;//count of lines in file
		int nextValue;//the parsed integer value from the file
		//prompt and reads in the file name
		InputStreamReader stdin = new InputStreamReader(System.in);
		BufferedReader keyboard = new BufferedReader(stdin);

		System.out.println("Enter the name of a file to process: ");
		fileNme = keyboard.readLine();
		//trys to open the file and handles arror if name is not valid
		try
		{
			//instead of reseting the file pointer I created 2 instnces of the same file
			FileReader fReader = new FileReader(fileNme);
			countFile = new BufferedReader(fReader);

			FileReader fReader2 = new FileReader(fileNme);
	                inputFile = new BufferedReader(fReader2);

		}
		catch(IOException e)
		{
			System.out.println("Error could not open file: " + fileNme);
			System.out.println("Cannot recover from error. Exiting.");
			return;
		}
		//counts all the lines in the file for the max size for the histograms value array
		dataLine = countFile.readLine();

		while(dataLine != null)
		{
			lineCount++;
			
			dataLine = countFile.readLine();
		}
		//creates the histogram from the line count
		histogram histo = new histogram(lineCount);
		//adds the values from the file into the histograms value array
		for(int i = 0; i < lineCount; i++)
		{
			try
			{
				nextValue = Integer.parseInt(inputFile.readLine());
				histo.add_value(nextValue);		
			}
			catch(NumberFormatException x)
			{
			}
		}
		//prints out the histogram with different groupings
		System.out.println("Histogram One - grouping = 10");
		histo.write();
		System.out.println("Histogram One - grouping = 20");
		histo.grouping = 20;
		histo.write();
		//test for a smaller grouping 
		//System.out.println("Histogram One - grouping = 5");
		//histo.grouping = 5;
                //histo.write();
		
	}
}
