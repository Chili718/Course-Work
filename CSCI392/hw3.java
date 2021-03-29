/*
//Title: HW3: Arrays and Files
//
//Name: Jon Tice
//
//Description:Reads integers from a given file and outputs the sum
//and list of integers in order if any.
//
//Class:CSCI392
//
//Date:9/10/2017
*/
import java.io.*;
import java.util.*;
public class hw3
{
	public static void main(String[] args) throws IOException
	{
		int[] numRay;//the array that will house the number if any from the file
		int sum = 0;//the sum of the values
		int i = 0;//variable for placing the number in the correct index
		int number = 0;//the variable that the parsed number will be assigned to 
		String fileNme;//namne of the file
		String dataLine;//data value from file
		BufferedReader inputFile;//file buffer

		//prompt and read the name of the file
		InputStreamReader stdin = new InputStreamReader(System.in);
		BufferedReader keyboard = new BufferedReader(stdin);

		System.out.print("Enter the name of a file to process: ");
		fileNme = keyboard.readLine();
		//try to open file if an error is generated the program will end
		try
		{
			FileReader freader = new FileReader(fileNme);
			inputFile = new BufferedReader(freader);
		}
		catch(IOException e)
		{
			System.out.println("Error could not open file: " + fileNme);
			System.out.println("Cannot recover from error. Exiting.");
			return;
		}
		//creating the array with the correct size using the raySize method
		numRay = new int[raySize(fileNme)];	
		//each line of the file will be parsed and if it is an integer it will
		//be added to the array
		dataLine = inputFile.readLine();

		while(dataLine != null)
		{
			try
			{
				number = Integer.parseInt(dataLine);
				//if the previous line generated an error the remaining statements will not execute	
				sum = sum + number;
				numRay[i] = number;
				i++;
			}
			catch(NumberFormatException fail)
			{
				//System.out.println("Error String is not valid Integer.");
			}

			dataLine = inputFile.readLine();
		}
		//sorts the array then prints the contents and sum of the array
		Arrays.sort(numRay);

		System.out.println("The sum of the integers");
		for(int j = 0; j < numRay.length; j++)
		{
			System.out.println(numRay[j]);
		}
		System.out.println("is "+sum+".");

	}
	//the method raySize counts the lines in the file and returns the value so
	//a properly sized array can be created 
	public static int raySize(String fileName) throws IOException
	{
		int count = 0;//count of elements in file

		//open the file that was properly validated before the method was called
		//if the method would be called before the file is validated an error could occur
		FileReader creader = new FileReader(fileName);
             	BufferedReader countFile = new BufferedReader(creader);
		//goes through file and counts elements until the end is reached
		String line = countFile.readLine();

		while(line != null)
		{
			//the count for the array size will only increase if the line is a number
			try
			{
				Integer.parseInt(line);			
				
				count++;	
			}
			catch(NumberFormatException h)
			{
				//no need to do anything if an error is generated 
			}
			
			line = countFile.readLine();
		}

		//System.out.println(count);

		return count;
	}
}
