/*
//Title: vertical_histogram.java
//
//Name: Jon Tice
//
//Description:Vertical histogram class that inherits from the parent histogram class
//to make a vertical histogram by overriding the write function
//
//Class:CSCI392
//
//Date:10/1/2017
*/
public class vertical_histogram extends histogram
{
	//the value to hold the
	private int height = 0;;

	public vertical_histogram(int sze)
	{
		super(sze);
	}

	public void write()
	{
		if(empty != true)
		{
			//creates the array that will hold the amount of values in each grouping
			histo = new int[(max/grouping)+1];
			//increases the amount of values in each grouping based on all the values in valRay 
			for(int i = 0; i < count; i++)
			{
				if(valRay[i] >= 0 && valRay[i] <= 99)
					histo[(valRay[i]/grouping)]++;
			}

			//find max height of the histogram
			for(int m = 0; m < histo.length; m++)
				if(histo[m]>height)
					height = histo[m];
			//prints out the *'s
			for(int u = height; u > 0; u--)
			{
				for(int z = 0; z <= (max/grouping); z++)
				{
					if(histo[z] >= u)
						System.out.print("  *   ");
					else
						System.out.print("      ");
				}
				System.out.println();
			}

			//prints out the ranges
			System.out.print(" ");
			System.out.print(0*grouping);
                        System.out.print("-");
                        System.out.print(grouping-1);
			if(grouping > 10)
                        	System.out.print(" ");
			else
				System.out.print("  ");

			for(int x = 1; x <= (max/grouping); x++)
			{
				System.out.print(x*grouping);
				System.out.print("-");
				System.out.print((x*grouping)+(grouping-1));
				System.out.print(" ");
			}
			
			System.out.println();
		}	
	}
}
