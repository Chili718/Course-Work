/*
//Title: HW4:Histogram 1.0
//
//Name: Jon Tice
//
//Description:Reads in integers from a given file and creates a histogram
//from that data
//
//Class:CSCI 392
//
//Date:9/16/2017
*/
import java.io.*;
import java.util.*;
public class hw4
{
	public static void main(String[] args) throws IOException
	{
		int[] histo;//histogram array
		int parVal;//parsed value
		int max = 0;//the max number in file
		boolean valid = false;//whether a valid histogram can be printed
		String fileNme, dataLine;//name of file and data value from file
		BufferedReader inputFile;//file buffer

		//prompt and read the name of the file
		InputStreamReader stdin = new InputStreamReader(System.in);
		BufferedReader keyboard = new BufferedReader(stdin);
		
		System.out.println("Enter the name of a file to process: ");
		fileNme = keyboard.readLine();
		//try to open file if an error is generated the program will end
		try
		{
			FileReader fReader = new FileReader(fileNme);
			inputFile = new BufferedReader(fReader);
		}
		catch(IOException e)
		{
			System.out.println("Error could not open file: " + fileNme);
			System.out.println("Cannot recover from error. Exiting.");
			return;
		}

		histo = new int[10];//create an array that holds the number of values in the 10 intervals from 0-99

		dataLine = inputFile.readLine();
		//goes through file and increases the index based on where the value falls in the histogram 
		//by dividing the value by ten
		while(dataLine != null)
		{
			try
			{
				parVal = Integer.parseInt(dataLine);
				
				if(parVal >= 0)	
					valid = true;
		
				if(parVal > max && parVal <= 99)//removes error if the number is out of histogram range
					max = parVal;
				if(parVal <= 99 && parVal >= 0)
					histo[(parVal/10)]++;//increases the number of values in that range
			}
			catch(NumberFormatException n)
			{
				//no need to do anything if error is generated 
			}

			dataLine = inputFile.readLine();
		}
		if(valid != false)
		{
			//prints out the histogram
			for(int i = 0; i <= (max/10); i++)
			{
				//range of bar in graph
				System.out.print(i*10);
				System.out.print("-");
				System.out.print((i*10)+9);
				//number of values represented by number of '*'
				System.out.print(" ");
				for(int j = 0; j < histo[i]; j++)
				{
					System.out.print("*");
				}
	
				System.out.println();
			}

		}		

	}
}
