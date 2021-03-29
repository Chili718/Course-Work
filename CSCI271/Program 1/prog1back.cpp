/*
/Program 1 Extra: Online Dating Service Proof of Concept 
/
/Jon Tice
/
/Reads in a master list of data and creates lists of individuals for the 
/customers based on their preference of gender and group size.
/
/CSCI 271
/
/1/25/2018
*/
#include<iostream>
#include<list>
#include<fstream>
#include<cstring>

using namespace std;

const int name_size = 21;//The size of the names cannot be larger than 20 characters

struct Person//The Struct for the people in the master list
{
	char p_Name[name_size];
	char p_Gender;
	float age;
};
struct Customer//The Struct for the customers that will be used when building the different groups 
{
	char c_Name[name_size];
	int groupSize;
	char genderPref;	
};

list<Person> fetchGroupList(list<Person> masterTemp, char nameTemp[name_size], int gSizeTemp, char gPrefTemp);
void printList(list<Person> listTemp);
bool calcDifference(float topAge, float bottomAge, float customerAge);

int main()
{
	fstream masterListFile, groupListFile;
	list <Person> masterList;
	list<Person>::iterator sortIter;	
	Person tempPerson;	
	Customer tempCustomer;

	masterListFile.open("/home/win.thackerw/271/peer/master1.dat", ios::in);
		
	if(!masterListFile)
	{
		cout<<"ERROR: Could not open file."<<endl;
	}
	
	//preforms the insertion sort on the data being placed into the master list
	masterListFile>>tempPerson.p_Name>>tempPerson.p_Gender>>tempPerson.age;	
	sortIter = masterList.begin();
        while(!masterListFile.eof())
        {
		masterList.insert(sortIter, tempPerson);

		sortIter = masterList.begin();

                masterListFile>>tempPerson.p_Name>>tempPerson.p_Gender>>tempPerson.age;

		while((sortIter != masterList.end()) && ((*sortIter).age > tempPerson.age))
			sortIter++;
        }
        
	masterListFile.close();

	//Test code to check if all of the individuals made it into the list in proper order
	//printList(masterList);
	
	groupListFile.open("/home/win.thackerw/271/peer/groups1.dat", ios::in);

        if(!groupListFile)
        {
                cout<<"ERROR: Could not open file."<<endl;
        }
	
	cout<<string(5,'\n');
	//Takes the data from the group file and uses it as input for the fetchGroupList function
        groupListFile>>tempCustomer.c_Name>>tempCustomer.groupSize>>tempCustomer.genderPref;	
	while(!groupListFile.eof())
        {
		printList(fetchGroupList(masterList, tempCustomer.c_Name, tempCustomer.groupSize, tempCustomer.genderPref));
		cout<<string(5,'\n');
		groupListFile>>tempCustomer.c_Name>>tempCustomer.groupSize>>tempCustomer.genderPref;
        }	

	groupListFile.close();
	
	return 0;
}
/*
/Function Name: fetchGroupList
/
/Description: Creates a group list based on the customers age and preferences of gender and group size
/
/Parameters: list<Person> masterTemp, char nameTemp[name_size], int gSizeTemp, char gPrefTemp
/
/Return Value: list<Person>
*/
list<Person> fetchGroupList(list<Person> masterTemp, char nameTemp[name_size], int gSizeTemp, char gPrefTemp)
{
	
	cout<<"Customer Name: "<<nameTemp<<" Group Size: "<<gSizeTemp<<" Gender Pref: "<<gPrefTemp<<endl<<endl;
	
	list<Person> *returnGroupList;
	
	returnGroupList = new list<Person>();
	
	list<Person>::iterator topIter, bottomIter, customerIter;
	
	//for loop that iterates to the customers position in the master list
	//This uses the strcmp function in cstring to compare the two char array as if they were strings
	for(customerIter = masterTemp.begin(); strcmp((*customerIter).p_Name,nameTemp) != 0 && customerIter != masterTemp.end(); customerIter++){}
	//if the customer is not found then an empty list will be returned
	if(customerIter == masterTemp.end())
	{
		cout<<"Customer Not Found!"<<endl;
		return (*returnGroupList);
	}

	//the customers data in the master list is the first element in their group list
	(*returnGroupList).push_back(*customerIter);
	
	//setting the two iterators to there starting position in the master list
	topIter = customerIter;
	bottomIter = customerIter;

	//Both bottom and top iterators will iterate once to there starting positions based on the customers
       	bottomIter++;
	if(topIter != masterTemp.begin())
		topIter--;

	//each iteration of the loop places the correct person in the group list based on the positions of the 3 iterators 
	for(int i = 0; i < gSizeTemp; i++)
	{
		//if the topIter has reached the begining of the list then the bottomIter will be the only one that changes position
		if(topIter == masterTemp.begin() && bottomIter != masterTemp.end())
		{
			
                          if(gPrefTemp == 'N')
                          {
	                  	(*returnGroupList).push_back(*bottomIter);
				bottomIter++;
                          }
                          else
                          {
				//the bottom iterator will move through the list until the end is met or a valid person is found
                                 while(bottomIter != masterTemp.end() && (*bottomIter).p_Gender != gPrefTemp)
                                 {
                                           bottomIter++;
                                 }
				//the list could go until the end without finding a valid person so this check is needed
                                 if(bottomIter != masterTemp.end())
				 {
                                           (*returnGroupList).push_back(*bottomIter);
					   bottomIter++;
				 }
                          }
		}//if the bottomIter has reached the end of the list then the topIter will be the only one that changes position
		else if(topIter != masterTemp.begin() && bottomIter == masterTemp.end())
		{
                        if(gPrefTemp == 'N')
                        {
                                 (*returnGroupList).push_back(*topIter);
				 topIter--;
                        }
                        else
                        {
				//the top iterator will move through the list until the end is met or a valid person is found
                                 while(topIter != masterTemp.begin() && (*topIter).p_Gender != gPrefTemp)
                                 {
                                         topIter--;
                                 }
				//the list could go until the beginning without finding a valid person so this check is needed
                                 if(topIter != masterTemp.begin())
				 {
                                         (*returnGroupList).push_back(*topIter);
					 topIter--;
				 }
                        }

		}//if neither iterators are at their respective end then a comparision between both will need to be made
		else if(topIter != masterTemp.begin() && bottomIter != masterTemp.end())
		{
			//if the gender preference does not matter a comparision of age will be made at the current iterators positions
                        if(gPrefTemp == 'N')
                        {
			  
                                if(calcDifference((*topIter).age, (*bottomIter).age, (*customerIter).age))
                                {
                                        (*returnGroupList).push_back(*topIter);
                                        topIter--;;
                                }
                                else
                                {
                                        (*returnGroupList).push_back(*bottomIter);
                                        bottomIter++;
                                }

                        }//if the gender preference matters 
                        else
                        {
				//both top and bottom iterators will move through the list until the end is met or a valid person is found
                        	while((topIter != masterTemp.begin() && ((*topIter).p_Gender != gPrefTemp)))
                                {
                                	topIter--;
                                }
                                while((bottomIter != masterTemp.end()) && ((*bottomIter).p_Gender != gPrefTemp))
                                {
                                        bottomIter++;
                                }

				//there are three scenarios that could happen
				//one: both iterators find a valid person so they are compared
                                if(((*topIter).p_Gender == gPrefTemp) && ((*bottomIter).p_Gender == gPrefTemp))
                                {
						
                                	if(calcDifference((*topIter).age, (*bottomIter).age, (*customerIter).age))
                                        {
                                                (*returnGroupList).push_back(*topIter);
                                                topIter--;
                                        }
                                        else
                                        {
                                                (*returnGroupList).push_back(*bottomIter);
                                        	bottomIter++;
                                        }

                                }//two: the topIter finds a valid person while the bottomIter reaches the end of the list and doesn't
                                else if(((*topIter).p_Gender == gPrefTemp) && ((*bottomIter).p_Gender != gPrefTemp))
                                {
                                        (*returnGroupList).push_back(*topIter);
                                        topIter--;
                                }//three: vice versa of the statement above
                                else
                                {
                                        (*returnGroupList).push_back(*bottomIter);
                                	bottomIter++;
                                }
                        }
		}
	}
	
	//checks if the desired number of individuals has been met
	//it is the size -1 becasue the customer is part of their own list but does not count
	if( ((*returnGroupList).size() - 1) != gSizeTemp )
		cout<<"We are sorry to inform you that our master list does not\n"
		"contain enought individuals to satisfy your request.\n"
		"Please contact customer support for more info.\n"<<endl;

	return (*returnGroupList);
}
/*
/Function Name: printList
/
/Description: Prints all of the elements in the list passed from begining to end
/
/Parameters: list<Person> listTemp
/
/Return Value: None
*/
void printList(list<Person> listTemp)
{
	list <Person>::iterator fIter;
	cout<<"----------"<<endl;
	for(fIter = listTemp.begin(); fIter != listTemp.end(); fIter++)
        {
                cout<<"Name: "<<(*fIter).p_Name<<" Gender: "<<(*fIter).p_Gender<<" Age: "<<(*fIter).age<<endl;
                cout<<"----------"<<endl;
        }
}
/*
/Function Name: calcDifference
/
/Description: Calculates the age difference between the ages passed
/	      if the top is closer or the difference is equal the function returns true.
/	      This function was created to remove the huge line of if logic 
/             that originally calculated this same thing.
/
/Parameters: list<Person> listTemp
/
/Return Value: bool
*/
bool calcDifference(float topAge, float bottomAge, float customerAge)
{
	if(topAge - customerAge <= customerAge - bottomAge)
		return true;
	else
		return false;
}
