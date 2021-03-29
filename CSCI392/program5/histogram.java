/*
//Title: histogram.java
//
//Name: Jon Tice
//
//Description:histogram class file contains methods to create and print a histogram 
//containing values from 0-99 with the ability to change the grouping 
//
//Class:CSCI392
//
//Date:9/23/2017
*/
import java.util.*;
public class histogram
{
	//array of values that the histogram will be made of
	private int[] valRay;
	//the highest numerical value in the histogram
	private int max = 0;
	//count of all the values that are added to valRay
	private int count = 0;
	//until a valid element is added this will remain true 
	private boolean empty = true;
	//public value so the grouping of the histogram can be changed 	
	public int grouping = 10;
	//constructor that is passed an integer for the array size
	public histogram(int raySize)
	{
		valRay = new int[raySize];
	}
	//method adds the value passed to the array holding the values for histogram
	public void add_value(int val)
	{
		//checks if the value array is full to remove out of bounds index
		if(count != valRay.length)
		{
			if(val > max && val <= 99)
			{
				max = val;
				empty = false;
			}

			valRay[count] = val;
			count++;
		}
		else
		{
			System.out.println("The histogram is full! No more values can be added.");
		}
	}
	//method prints out the histogram
	public void write()
	{
		//if the array is empty no histogram will be printed 
		if(empty != true)
		{
			for(int i = 0; i <= (max/grouping); i++)
			{
				//Grouping of the values
				System.out.print(i*grouping);
				System.out.print("-");
				System.out.print((i*grouping)+(grouping-1));

				System.out.print(" ");
				//number of values in the grouping range
				for(int j = 0; j < count; j++)
				{
					if(valRay[j] >= i*grouping && valRay[j] <= (i*grouping)+(grouping-1))
						System.out.print("*");
				}

				System.out.println();
			}	
		}
		else
		{
			System.out.println("The histogram is empty! Only values between 0-99 are valid.");
		}
	}
}
