/*
*Title:Program 1
*
*Name:Jon Tice
*
*Description: Obtains the average of a collection of numbers the user chose.
*
*Class:CSCI431
*
*Date:9/21/2018
*/

import java.io.*;
import java.lang.*;

class program1
{
	public static void main(String[] args) throws IOException
	{

		InputStreamReader dev = new InputStreamReader(System.in);
		BufferedReader keyboard = new BufferedReader(dev);

		String inp;
		int count;
		double output;
		//gain the total amount of number that will be input for the array declaration
		System.out.println("Enter the integer amount of numbers you would like to average: ");
		inp = keyboard.readLine();
		
		try
		{
			count = Integer.parseInt(inp); 		
		}//catch the possibility the user does not enter a integer
		catch(NumberFormatException x)
		{
			System.out.println("User did not enter valid integer. Program Exiting.");

			return;
		}
		//the array is of type double because the user may still enter integers and doubles
		//interchangeably plus the average will be a double anyways 
		double[] raytay = new double[count];

		System.out.println("Please enter " + count + " number(s): ");
		
		try
		{
			//read in the numbers and populate the array
			for(int i = 0; i < count; i++)
			{
				inp = keyboard.readLine();
				raytay[i] = Double.parseDouble(inp);
			}
		}//catch the possibility the user does not enter a number
		catch(NumberFormatException x)
                {
                        System.out.println("User did not enter valid number. Program Exiting.");

                        return;
                }
		//calculate the average using the average function and display
		output = average(raytay);
		System.out.println("The average of the numbers is: ");
		System.out.println(output);
	}
/*
*Function Name: average
*
*Description:Function is passed an array of type double and returns the average of
*the numbers in it 
*
*Parameter:double[] ray
*
*Return Value; double avg
*/
	public static double average(double[] ray)
	{
		double avg = 0.00;
		//adds all the values together in array to avg
		for(int s = 0; s < ray.length; s++)
		{
			avg = avg+ray[s];
		}
		//use the array length to help calculate the average
		avg = avg/ray.length;
		//return the average
		return avg;
	}
}
