/*
 *File IO
 *
 *Jon Tice
 *
 *Reads in bank information and output from file
 *and allows users to select specific records to view
 *
 *CSCI 208
 *
 *9/18/16
 */
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

struct User//User structure
{
	int AccID;
	char FirstName[51];
	char LastName[51];
	double balance;
};

User readUser();//Reads in the user input for the variables in the structure
void printUser(const User& data);//Is passed a user variable and output all of the data in the user variable

int main()
{
	const int number = 12;//determines the number of records to be input
	int record = 1;//gives the RR number as the index
	int recordInp;//hold the RR number that is input

	User one;//dummy user for main class
	User AllUsers[number];//array that will hold all of the users

	for(int i = 0; i < number; i++)//loops the users input depending on how big the array is
	{
		AllUsers[i] = readUser();//takes the user variable returned from the function and stores in array

	}

	fstream file;//declares the input and output file variable

	file.open("user.dat", ios::out | ios::binary);//opens the file for output from the user
	if(!file)//shows if the file is not opened
	{
		cout<<"Could not open file.";

		return 0;
	}

	file.write(reinterpret_cast<char *>(AllUsers), sizeof(AllUsers));//writes the whole user array into the data file
	file.close();//close the file


	file.open("user.dat", ios::in | ios::binary);//opens the file for input from the data file
	if(!file)//shows if the file is not opened
	{
		cout<<"Could not open file.";

		return 0;
	}

	file.read(reinterpret_cast<char*>(&one), sizeof(User));//primes the while loop so the last line of information is not repeated

	while(!file.eof())//while the pointer is not at the end of the file
	{
		cout<<"Relative Record Number: "<<record<<", ";//prints the relative record number before the user is because it is not part of array
		printUser(one);//uses the print function to print the user
		file.read(reinterpret_cast<char*>(&one), sizeof(User));//reads user input from file and stores in dummy user
		cout<<endl;//so all the users are not printed on one line
		record++;//record number is increased by one

	}

	file.close();//close the file


	char answer ='y';//primes the loop to keep taking records to find
	int place;//determines the place of the record from the RR number
	file.open("user.dat", ios::in | ios::binary);//opens the file for input from the data file
	if(!file)//shows if the file is not opened
	{
		cout<<"Could not open file.";

		return 0;
	}

	while(answer == 'y' || answer =='Y')//loop to find a record
	{

		cout<<"Enter a records RR Number that you would like to access: ";
		cin>>recordInp;//gets the RR number

		while((recordInp <= 0) || (recordInp > number))//if the RR number is invalid it will keep asking for a new number
		{
			cout<<"Input Invalid.";
			cout<<"Enter a valid records RR Number that you would like to access: ";
			cin>>recordInp;//gets the RR number
		}

		place = (recordInp-1)*sizeof(User);//determines the place at which to put the cursor from RR number
		file.seekg(place, ios::beg);//places the cursor at the calculated point from the beginning

		file.read(reinterpret_cast<char*>(&one), sizeof(User));//reads the corresponding user into the dummy user
		printUser(one);//uses the print function to print the user
		cout<<endl;

		cout<<"If you would like to access another record type 'Y' or 'N' if you wouldn't:";
		cin>>answer;//asks the user to continue the loop
	}

	cout<<"User did not want to continues, program closing. Goodbye.";//prints closing statement

	file.close();//close the file

	return 0;
}
/*Function:readUser
 *
 * Description:Reads in the user input for the variables in the structure
 * and then returns all values in a dummy user
 *
 * Parameters: None
 *
 * Returns: Dummy user with recently input data
 */
User readUser()
{

	User temp;//dummy user to temporarily store data

	cout<<"Enter your account ID: ";
	cin>>temp.AccID;

	cout<<"Enter your first name: ";
	cin>>temp.FirstName;

	cout<<"Enter your last name: ";
	cin>>temp.LastName;

	cout<<"Enter your account balance: ";
	cin>>temp.balance;

	return temp;
}
/*Function:printUser
 *
 * Description:Is passed a user variable and output all of the data in the user variable
 *
 * Parameters: User structure variable to be output
 *
 * Returns: Dummy None
 */
void printUser(const User& data)
{

	cout<<"Account Number: "<<data.AccID<<", Last Name: "<<data.LastName<<", First Name: "<<data.FirstName<<", Balance: "<<data.balance;

}
