/*
 *Luhn Checksum
 *
 *Jon Tice
 *
 *Validates credit card information
 *
 *CSCI 208
 *
 *9/4/16
 */

#include <cstdlib>
#include <iostream>

#define enter '\n'

using namespace std;

int doubleNum(int num);

int main()
{
	int inputNumber, one = 0, two = 0, sumTotal =0, count= 0;

	int index = 1;//index starts at 1 because the must alternate between even and odd

	char inputChar;//user inputs as a char so a string of characters can be entered rather than one at a time

	cout<<"Enter a number to be validated: ";

	inputChar = cin.get();//primes while loop to continue input

	while(inputChar != enter)//until enter has been pressed the loop will continue
	{

		count++;//keeps tab on if it is an even or an odd length with counter

		inputNumber = atoi(&inputChar);//converts character to integer

		if(index % 2 ==0)//If it is an odd index then the number will be
		{

			one = inputNumber + one;
			//A running total in length is kept for even and odd because we don't know if the length will be odd or even
			two = doubleNum(inputNumber) + two;

		}
		else
		{
			two = inputNumber + two;
			//A running total in length is kept for even and odd because we don't know if the length will be odd or even
			one = doubleNum(inputNumber) + one;
		}

		inputChar = cin.get();//continues to gain input from the user

		index++;//only increases if the loop continues if the user doens't enter more than one character
	}

	if(count % 2 ==0)//If there was an even or odd length give the corresponding total
	{
		sumTotal = one;//If it has an even length
	}
	else
	{
		sumTotal = two;//If it has an odd length
	}

	if (sumTotal % 10 == 0)//gives final decision if the number is divisible by ten then its valid
	{
		cout <<  "The number you entered is valid.";
	}
	else
	{
		cout << "The number "<<sumTotal<<" is not valid.";
	}

}

/*doubleNum
 *
 *Doubles the number that is passed and correctly handles if it is a double digit number
 *
 *int num
 *
 *return value;
 */

int doubleNum(int num)
{
	int value, doubledNumber = num * 2;

	if(doubledNumber <= 10)//determines if the number is double digit or not
	{
		value = doubledNumber;
	}
	else
	{
		value =(doubledNumber % 10) + 1;//the number will not be bigger than 18
										//so the the sum will always be
		 	 	 	 	 	 	 	 	// +1 the last digit and %10 gives us the last digit
	}

	return value;//returns doubles number
}

