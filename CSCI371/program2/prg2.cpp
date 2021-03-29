/*
//Title: Program 2: FSM for language of numbers
//
//Name: Jon Tice
//
//Description: Reads in strings and determines if they are a valid
//number by using a finite state machine
//Class: CSCI 371
//
//Date: 10/4/2017
*/
#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>

using namespace std;

enum state{Start = 0, p2 = 1, p3 = 2, p4 = 3, p5 = 4, p6 = 5, p7 = 6, Dead};

int main()
{
	ifstream inpFile;
	string fileNme;
	//string containing all valid characters that are not numbers
	string sette = "+-.E";
	int i, convert;
	state currentState;
	//the dataline read from the input file
	char dataLine[15];
	//ask for file name and take input
	cout<<"Enter the name of the file you would like to process: "<<endl;

	cin>>fileNme;

	inpFile.open(fileNme.c_str());
	//check if file opened properly
	if(!inpFile)
	{
		cout<<"ERROR: Could not open file. Cannot Recover. Exiting."<<endl;

		return 0;
	}	
	//next state table (although each number 0-9 goes to the same place I decided to keep them individual 
	//columns in case their would need to be a specific case changed for a number
	state nextStateTable[7][14] = { {p2, p2, p2, p2, p2, p2, p2, p2, p2, p2, p7, p7, Dead, Dead},
					{p2, p2, p2, p2, p2, p2, p2, p2, p2, p2, Dead, Dead, p3, Dead},
					{p3, p3, p3, p3, p3, p3, p3, p3, p3, p3, Dead, Dead, Dead, p4},
					{p6, p6, p6, p6, p6, p6, p6, p6, p6, p6, p5, p5, Dead, Dead},
					{p6, p6, p6, p6, p6, p6, p6, p6, p6, p6, Dead, Dead, Dead, Dead},
					{p6, p6, p6, p6, p6, p6, p6, p6, p6, p6, Dead, Dead, Dead, Dead},
					{p2, p2, p2, p2, p2, p2, p2, p2, p2, p2, Dead, Dead, p3, Dead}
				      };

	inpFile>>dataLine;

	while(!inpFile.eof())
	{
		//reset the current state and i 
		i = 0;
		currentState = Start;

		while(dataLine[i] != '\0' && currentState != Dead)	
		{
			
			if(isdigit(dataLine[i]))
			{
				//converting character into an integer
				convert = dataLine[i] - '0';

				currentState = nextStateTable[currentState][convert];
			}//if the character dataLine[i] is in the string containing all valid characters not numbers
			else if(sette.find(dataLine[i]) != string::npos)
			{
				//switch the character with corresponding index in array
				switch(dataLine[i])
				{
					case '+':
						convert = 10;
						break;
					case '-':
						convert = 11;
						break;
					case '.':
						convert = 12;
						break;
					case 'E':
						convert = 13;
						break;
					default:
						convert = 0;
				}
				
				currentState = nextStateTable[currentState][convert];
			}//if the character is not a digit or in the set of characters sette it is not a valid number
			else
			{
				currentState = Dead;
			}
			//move to next character in the dataLine
			i++;

		}
		//print out the string and if it is a number or not depending on the current state (accpeting or not)
		if(currentState == p4 || currentState == p5 || currentState == p7 || currentState == Dead)
		{
			cout<<dataLine<<" - No"<<endl;
		}
		else
		{
			cout<<dataLine<<" - Yes"<<endl;
		}

		inpFile>>dataLine;
	}
	
	inpFile.close();

	return 0;

}
