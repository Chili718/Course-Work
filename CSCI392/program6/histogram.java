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
	protected int[] valRay;
	//array to hold the number of values in each grouping 
	protected int[] histo;
	//the highest numerical value in the histogram
	protected int max = 0;
	//count of all the values that are added to valRay
	protected int count = 0;
	//until a valid element is added this will remain true 
	protected boolean empty = true;
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
			histo = new int[(max/grouping)+1];

			for(int i = 0; i < count; i++)
			{
				if(valRay[i] >= 0 && valRay[i] <= 99)
					histo[(valRay[i]/grouping)]++;
			}

			for(int j = 0; j <= (max/grouping); j++)
			{
				//Grouping of the values
				System.out.print(j*grouping);
				System.out.print("-");
				System.out.print((j*grouping)+(grouping-1));

				System.out.print(" ");
				//number of values in the grouping range
				for(int k = 0; k < histo[j]; k++)
				{
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
