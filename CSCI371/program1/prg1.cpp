/*
//Program 1: Roman Numeral FSM
//
//Jon Tice
//
//Reads in Roman Numerals from 1 to 100 from a file and outputs the base ten value of those
//that are valid.
//
//CSCI 371
//
//9/22/2017
*/
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;
//enums for state and action to represent the various states and actions 
enum state {Start, Dead, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14};
enum action {add1, add5, add10, add50, add100, add3, add8, add30, add80, None}; 

int main()
{
	fstream romanFile;
	string fileNme;
	int i, count;
	state stte;
	action act;
	//the greatest length of a valid roman numeral between 1-100 is 8 plus the null terminator
	//but if the string is of length 9 or more and the first 8 are valid then the 9th character 
	//will show it is invalid
	char inp[10];

	//asks for file name and opens the file if valid if not the program terminates
	cout<<"Enter the name of the file you would like to process: "<<endl;

	cin>>fileNme;	

	romanFile.open(fileNme.c_str(), ios::in);

	if(!romanFile)
	{
		cout<<"ERROR: Could not open file. Cannot Recover. Exiting."<<endl;

		return 0;
	}
	
	romanFile>>inp;
	
	while(!romanFile.eof())
	{
		//reset the value of RN, the state, and i 
		count = 0;
		i = 0;
		stte = Start;
		//the finite state machine that determines if the string read from the file is a valid RN
		while(inp[i] != '\0' && stte != Dead)
		{
			//next state table
			switch(stte)
			{
				case Start:
					switch(inp[i])
					{
						case 'I':
							stte = P8;
							act = add1;
							break;
						case 'V':
							stte = P4;
							act = add5;
                                                        break;
						case 'X':
							stte = P1;
							act = add10;
                                                        break;
						case 'L':
							stte = P10;
							act = add50;
                                                        break;
						case 'C':
							stte = P11;
							act = add100;
                                                        break;
						default:
							stte = Dead;
							act = None;
					}
					break;
				case P1:
					switch(inp[i])
                                        {
                                                case 'I':
							stte = P8;
							act = add1;
                                                        break;
                                                case 'V':
							stte = P4;
							act = add5;
                                                        break;
                                                case 'X':
							stte = P2;
							act = add10;
                                                        break;
                                                case 'L':
							stte = P12;
							act = add30;
                                                        break;
						case 'C':
                                                        stte = P13;
                                                        act = add80;
                                                        break;
                                            	default:
							stte = Dead;
							act = None;
                                        }
					break;
				case P2:
					switch(inp[i])
                                        {
                                                case 'I':
							stte = P8;
							act = add1;
                                                        break;
                                                case 'V':
							stte = P4;
							act = add5;
                                                        break;
                                                case 'X':
							stte = P3;
							act = add10;
                                                        break;
                                                default:
                                                        stte = Dead;
							act = None;
                                        }
					break;
				case P3:
					 switch(inp[i])
                                        {
                                                case 'I':
							stte = P8;
							act = add1;
                                                        break;
                                                case 'V':
							stte = P4;
                                                        act = add5;
                                                        break;
                                                default:
                                                        stte = Dead;
							act = None;
                                        }
                                        break;
				case P4:
					switch(inp[i])
                                        {
                                                case 'I':
							stte = P5;
							act = add1;
                                                        break;
                                                default:
                                                        stte = Dead;
							act = None;
                                        }
                                        break;
				case P5:
					switch(inp[i])
                                        {
                                                case 'I':
							stte = P6;
                                                        act = add1;
                                                        break;
                                                default:
                                                        stte = Dead;
							act = add1;
                                        }
                                        break;
				case P6:
					switch(inp[i])
                                        {
                                                case 'I':
							stte = P7;
                                                        act = add1;
                                                        break;
                                                default:
                                                        stte = Dead;
							act = None;
                                        }
                                        break;
				case P7:
					stte = Dead;
					act = None;
                                        break;
				case P8:
					switch(inp[i])
                                        {
                                                case 'I':
							stte = P6;
							act = add1;
                                                        break;
                                                case 'V':
							stte = P14;
							act = add3;
                                                        break;
                                                case 'X':
							stte = P9;
							act = add8;
                                                        break;
                                                default:
                                                        stte = Dead;
							act = None;
                                        }
                                        break;
				case P9:
					stte = Dead;
					act = None;
					break;
				case P10:
					switch(inp[i])
                                        {
                                                case 'I':
							stte = P8;
							act = add1;
                                                        break;
                                                case 'V':
							stte = P4;
							act = add5;
                                                        break;
                                                case 'X':
							stte = P1;
							act = add10;
                                                        break;
                                                default:
                                                        stte = Dead;
							act = None;
                                        }
                                        break;
				case P11:
					stte = Dead;
					act = None;
                                        break;
				case P12:
					switch(inp[i])
                                        {
                                                case 'I':
							stte = P8;
							act = add1;
                                                        break;
                                                case 'V':
							stte = P4;
							act = add5;
                                                        break;
                                                default:
                                                        stte = Dead;
							act = None;
                                        }
                                        break;
				case P13:
					switch(inp[i])
                                        {
                                                case 'I':
							stte = P8;
							act = add1;
                                                        break;
                                                case 'V':
							stte = P4;
							act = add5;
                                                        break;
                                                default:
                                                        stte = Dead;
							act = None;
                                        }
                                        break;
				case P14:
					stte = Dead;
					act = None;
                                        break;
				default:
					cout<<"Invalid State.";	
			}
			//action table
			switch(act)
			{
				case add1:
					count = count + 1;
					break;
				case add5:
					count = count + 5;
                                        break;
				case add10:
					count = count + 10;
                                        break;
				case add50:
					count = count + 50;
                                        break;
				case add100:
					count = count + 100;
                                        break;
				case add3:
					count = count + 3;
                                        break;
				case add8:
					count = count + 8;
                                        break;
				case add30:
                                        count = count + 30;
                                        break;
				case add80:
					count = count + 80;
                                        break;
				default:
					cout<<inp<<" = ERROR, not a Roman Number from 1 to 100."<<endl;
			}

			i++;
		
		}
		//prints the valid RN with base ten value
		if(stte != Dead)
			cout<<inp<<" = "<<count<<endl;
		//reads next line in the file into inp
		romanFile>>inp;
	}
	
	return 0;
}
