/*
*Program 5: hashTable.h
*
*Jon Tice
*
*The header/implementaion class for the hashTable class
*
*CSCI 271
*
*4/5/17
*/
#ifndef hashTable_h
#define hashTable_h

#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

class hashTable
{
	private:
		int tableSize;
		string* hashRay;	
	public:
		hashTable(int size);
		int hash(string key);
		void insertItem(string item);
		bool isFull();
		void search(string toFind, unsigned int &probes, int &successful, int &unsuccessful);
};

//Constructor
hashTable::hashTable(int size)
{
	tableSize = size;

	hashRay = new string[tableSize];
}
/*
*Function: hash
*
*Description: is passed a value and assigns an index number 
*for the item in the hash table
*
*Parameter: string key 
*
*Return Value: int
*/
int hashTable::hash(string key)
{
	//creates a index from the string using string folding
	long hashNum = 0;
	int index;
	int length = key.length()/4;

	for(int i = 0; i < length; i++)
	{
		string c = key.substr(i*4, (i*4)+4);
		long mult = 1;
		for(int k = 0; k < c.length(); k++)
		{
			hashNum = hashNum+(c[k] * mult);
			mult = mult * 256;
		}
	}

	index = abs(hashNum) % tableSize;
	
	return index;
}
/*
*Function: insertItem
*
*Description: inserts the item passed into the table
*
*Parameter: string item
*
*Return Value: none
*/
void hashTable::insertItem(string item)
{
	int index = hash(item);
	//bool full = isFull();	

	//cout<<index<<endl;

	if(hashRay[index]=="")
	{
		hashRay[index] = item;
	}
	else
	{
		while(hashRay[index]!="")
		{
			if(index == tableSize-1)
				index = 0;
			else
				index++;
		}
		hashRay[index] = item;
	}		
}
/*
*Function: isFull
*
*Description: determines if the table is full
*
*Parameter: None
*
*Return Value: bool
*/
bool hashTable::isFull()
{
	for(int i = 0; i < tableSize; i++)
	{
		if(hashRay[i]=="")
		{
			return false;
		}
	}
	return true;
}
/*
*Function: search
*
*Description:searches the table for the value passed and updates the # of 
*probes, and whether it was a successful search or not
*
*Parameter: string toFind, int &probes, int &successful, int &unsuccessful
*
*Return Value: none
*/
void hashTable::search(string toFind, unsigned int &probes, int &successful, int &unsuccessful)
{

	int index = hash(toFind);

	//cout<<index<<endl;

	int end = index-1;
	bool found = false;
	
	if(hashRay[index] == toFind)
	{
		found = true;
		probes++;
		successful++;
	}
	else
	{
		probes++;
	}

	while(index != end && found != true)
	{
		if(index == tableSize-1)
                {
                        index = -1;
                }

		index++;
		if(hashRay[index] == toFind)
		{
			//cout<<"found"<<endl;
			found = true;
                	probes++;
                	successful++;
		}
		else
		{
			probes++;
		}

	}

	if(found == false)
	{
		//cout<<"not found"<<endl;
		unsuccessful++;
	}
}
#endif
