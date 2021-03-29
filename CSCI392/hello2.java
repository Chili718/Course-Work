/*
//Title: HW2: Hello World 2.0 
//
//Name: Jon Tice
//
//Description: Prints corresponding message based on arguments passed
//
//Class: CSCI 392
//
//Date: 9/3/2017
*/
public class hello2
{
	public static void main(String[] args)
	{
		int numLoops;

		if(args.length > 2)//if more than the maximum number of arguments is entered it will generate an error message
		{
			System.out.println("Usage Error: Too Many Arguments");
		}
		else if(args.length == 2)
		{
			int count;

			try
			{

				count = Integer.parseInt(args[0]);//if this generates an error then args[0] contains a name
				
				try//this second try/catch removes the possibility of having the two integers produce an invalid statment such as 'Hello 4'
				{
					count = Integer.parseInt(args[1]);

					System.out.println("Usage Error: Enter a name and/or integer.");
				}
				catch(NumberFormatException fail)
				{
					for(int i = 0; i < count; i++)//prints hello with the name in args[1], arg[0] times
                	                {
        	                                System.out.println("Hello " + args[1]);
	                                }

				}

			}
			catch(NumberFormatException fail)
			{
				try
				{
					count = Integer.parseInt(args[1]);//if this generates an error again then both arguments are strings

					for(int h = 0; h < count; h++)//prints hello with the name in args[0], arg[1] times
	                                {
                	                        System.out.println("Hello " + args[0]);
        	                        }

				}
				catch(NumberFormatException fail2)//if both arguments are strings then the error message will print
				{
					System.out.println("Usage Error: Enter a name and/or integer.");
				}
			}
		}
		else if(args.length == 1)//only two possibilities for one argument
		{
			try//if it is an integer it will print "Hello World" count2 number of times
			{
				int count2;
				
				count2 = Integer.parseInt(args[0]);//if this generates an error we know it is not a number

				for(int i = 0; i < count2; i++)
				{
					System.out.println("Hello World");
				}
			}
			catch(NumberFormatException fail3)//if args[0] is not a number it is a name so it will be concatenated with 'Hello '
			{
				System.out.println("Hello " + args[0]);
			}
		}
		else//if no arguments are entered the program will simply print 'Hello World'
		{
			System.out.println("Hello World");
		}
		
	}	
}
