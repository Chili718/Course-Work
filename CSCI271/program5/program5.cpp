/*
*Program 5: program5.cpp
*
*Jon Tice
*
*The "main" class for program 5
*
*CSCI 271
*
*4/3/2017
*/
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include"hashTable.h"

using namespace std;

int main(int argc, char* argv[])
{
	fstream insertDat, searchDat;
	char insertWrd[31];
	char searchWrd[31];

	int size = atoi(argv[1]);
	int inputSize = 200000;
	
	unsigned int probes = 0;
	int successful = 0, unsuccessful = 0;

	float avg;

	hashTable one(size);	
	
	insertDat.open("/home/win.thackerw/271/sort.dat", ios::in);

	if(!insertDat)
	{
		cout<<"ERROR::File did not open."<<endl;
	}
	
	for(int i = 0; i < inputSize; i++)
	{
		insertDat>>insertWrd;

		one.insertItem(insertWrd);
	}
	
	searchDat.open("/home/win.thackerw/271/search.dat", ios::in);

        if(!searchDat)
        {
                cout<<"ERROR::File did not open."<<endl;
        }
	
	while(!searchDat.eof())
	{
		searchDat>>searchWrd;

		one.search(searchWrd, probes, successful, unsuccessful);
	}

	avg = probes/(unsuccessful+successful);

	cout<<"Number of Probes:"<<probes<<endl;
	cout<<"Average Number of Probes:"<<avg<<endl;
	cout<<"Number of Unsuccessful searches: "<<unsuccessful<<endl;
	cout<<"Number of Successful searches: "<<successful<<endl;
	

	return 0;

}
