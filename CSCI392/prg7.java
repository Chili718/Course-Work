/*
//Title: Image Inversion
//
//Name: Jon Tice
//
//Description: Takes the name of a jpeg file and inverts the images RGB values pixel by pixel
//to invert the image
//Class: CSCI 392
//
//Date:10/8/2017
*/
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.*;
import javax.imageio.*;
public class prg7
{
	public static void main(String[] args)
	{
		BufferedImage image = null;
		int p, a, r, g ,b;
		//checks if an argument was passed for file name
		if(args.length != 1)
		{
			System.out.println("Usage Error: proper amount of arguments not given. Exiting.");
			return;
		}//the minimum length for a valid jpeg file is 5 characters
		else if(args[0].length() > 5)
		{	//checking if the file passed is a jpeg
			if(!(args[0].substring(args[0].length() - 4, args[0].length())).equals(".jpg"))
			{
				System.out.println("ERROR: image file is not a jpeg. Exiting.");
				return;
			}
		}
		//gets the image data from the file in args[0]
		try
		{
			image = ImageIO.read(new File(args[0]));
		}
		catch(IOException e)
		{
			System.out.println("ERROR: image file not found. Cannot Recover. Exiting.");

			return;
		}
		//creating the name for the new inverted image file
		String outputFile = "inv_" + args[0];
		//track the loading of the image
		MediaTracker tracker = new MediaTracker(new Component() {});
		tracker.addImage(image, 0);

		try
		{
			tracker.waitForID(0);
		}
		catch(InterruptedException l)
		{}

		for(int y = 0; y < image.getHeight(); y++)
		{
			for(int x = 0; x < image.getWidth(); x++)
			{
				p = image.getRGB(x, y);
				//get the specific red, green, blue, and alpha from p
				a = (p>>24)&0xff;
				r = (p>>16)&0xff;
				g = (p>>8)&0xff;
				b = p&0xff;
				//subtract RGB from 255
				r = 255 - r;
				g = 255 - g;
				b = 255 - b;
				//set the new RGB value
				p = (a<<24) | (r<<16) | (g<<8) | b;

				image.setRGB(x, y, p);
			}
		}
		//write the inverted image to the jpeg file with the name created earlier
		try
		{
			ImageIO.write(image, "jpg", new File(outputFile));
		}
		catch(IOException j)
		{}
	}

}
