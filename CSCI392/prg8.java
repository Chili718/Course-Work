/*
//Title: Green Screen
//
//Name: Jon Tice
//
//Description:reads in two files, the output file name, the tolerance percent and removes the green 
//pixels from the foreground and replaces it with the corresponding background pixels
//Class: CSCI 392
//
//Date:10/20/2017
*/
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.*;
import javax.imageio.*;
public class prg8
{
	public static void main(String[] args) throws IOException
	{
		BufferedImage foreground = null;
		BufferedImage background = null;

		InputStreamReader stdin = new InputStreamReader(System.in);
		BufferedReader keyboard = new BufferedReader(stdin);

		String fore, back, outFile, pInp, isJpeg, isJpeg2;
		int p, a, b, r, g, backX, backY, percentVal;
		double percent;
		float[] hsv; 
		float hue;

		//getting the users input for the 2 input file and name for output
		System.out.println("Enter the name of the jpeg file that will have the green removed from it(the foreground): ");
		fore = keyboard.readLine();
		System.out.println("Enter the name of the jpeg file for the background that will replace the foregrounds green pixels: ");
		back = keyboard.readLine();
		System.out.println("Enter the name of the file for the output image including the '.jpg': ");
		outFile = keyboard.readLine();
		System.out.println("Enter the integer value for the percent you would like to increase the color range for green by: ");
		System.out.println("(The lighter the green the higher percent.)");
                pInp = keyboard.readLine();

		//convert the string containing the percent value entered to an int
		try
		{
			percentVal = Integer.parseInt(pInp);
		}
		catch(NumberFormatException x)
		{
			System.out.println("Invalid input entered. percent must be an integer. cannot recover. exiting.");
			return;
		}
		//converting the percent to decimal
		percent = percentVal*0.01;
		//removing the last 4 characters of both file names to determine if they are jpeg
		isJpeg = fore.substring(fore.length() - 4, fore.length());
		isJpeg2 = back.substring(fore.length() - 4, back.length());

		//the minimum length for a valid jpeg file is 5 characters
		if(fore.length() >= 5 || back.length() >= 5)
		{	
			//checking if the files given are jpegs
			if(fore.indexOf(".jpg") < 0 ||back.indexOf(".jpg") < 0 ||outFile.indexOf(".jpg") < 0)
      			{
       				System.out.println ("Usage Error: input file and output file must end in .jpg");
       				return;
      			}
		}
		
		//gets the image data from the files given 
		try
		{
			foreground = ImageIO.read(new File(fore));
			background = ImageIO.read(new File(back));
		}
		catch(IOException e)
		{
			System.out.println("ERROR: image file not found. Cannot Recover. Exiting.");

			return;
		}
		
		//track the loading of the image
		MediaTracker tracker = new MediaTracker(new Component() {});
		tracker.addImage(foreground, 0);
		MediaTracker tracker2 = new MediaTracker(new Component() {});
                tracker2.addImage(background, 0);

		
		try
		{
			tracker.waitForID(0);
			tracker2.waitForID(0);
		}
		catch(InterruptedException l)
		{}

		
		for(int y = 0; y < foreground.getHeight(); y++)
		{
			//calculates the corresponding y value to the possibly larger background image
			backY = (int)(((double)y/foreground.getHeight()) * background.getHeight());
			
			for(int x = 0; x < foreground.getWidth(); x++)
			{
				p = foreground.getRGB(x,y);
				a = (p>>24) & 0xff;
				r = (p>>16) & 0xff;
				g = (p>>8) & 0xff;
				b = p & 0xff;
				//getting the hue value from the RGB value 
				hsv = Color.RGBtoHSB(r, g, b, null);
				hue = hsv[0];				
				//calculates the corresponding x value to the possibly larger background image
				backX =(int)(((double)x/foreground.getWidth())*background.getWidth());
				//checks if the hue of the pixel is in the range of green hues (70-160)
				//and if the color is green depending on the percent given
				if((r+b) <= ((int)(g*percent)+g) && 70 <= (hue*360) && (hue*360) <= 160)
                                {
					//replacing the green pixel with the corresponding pixel in the background image
                                        foreground.setRGB(x, y, background.getRGB(backX, backY));
                                }

			}
		}

		//write the new image to the jpeg file with the name given earlier
		try
		{
			ImageIO.write(foreground, "jpg", new File(outFile));
		}
		catch(IOException j)
		{}
		
	}

}
