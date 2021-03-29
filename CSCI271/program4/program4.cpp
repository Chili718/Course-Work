//
//Program 4: program4.cpp
//
//Jon Tice
//
//Will use arguments passed to main from command line 
//to sort an array of a certain size using bubble, quick, insertion, or 
//merge sort and output the sorted data to sorted.dat
//
//CSCI271
//
//3/24/2018
//
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;

//O(n^2) sort
void bubbleSort(char* arrayArg[], int raySize);
//o(n log n) sort
void quickSort(char* arrayArg[], int left, int right);
//Additional O(n^2) sort
void insertionSort(char* arrayArg[], int raySize);
//Additional O(n log n) sort
void mergeSort(char* arrayArg[],char* temporary[], int left, int right);

int main(int argc, char* argv[])
{

	fstream inputfile;
	fstream outputfile;
	
	int size =  atoi(argv[1]);
	
	char** ray = new char*[size];
	char** rayTemp = new char*[size];
	char* word;

////////////////////////////////////////////////
//Opens data file and stores the values into the array
///////////////////////////////////////////////

	inputfile.open("/home/win.thackerw/271/sort.dat", ios::in);

	if(!inputfile)
        {
                cout<<"ERROR: file did not open."<<endl;
        }
	
	for(int i = 0; i < size; i++)
	{
		word = new char[31];
		inputfile>>word;
		ray[i] = word;
	}	
	
        inputfile.close();

/////////////////////////////////////////////////
// I commented which sort I was not using to test the other
/////////////////////////////////////////////////

	quickSort(ray, 0, size-1);

	//bubbleSort(ray, size);

	//insertionSort(ray, size);

	//mergeSort(ray, rayTemp, 0, size-1);

/////////////////////////////////////////////////
//Writes the sorted array into the file sorted.dat
/////////////////////////////////////////////////

	outputfile.open("sorted.dat", ios::out);
	
	if(!outputfile)
	{
		cout<<"ERROR: file did not open."<<endl;
	}

	for(int i = 0; i < size; i++)
        {
		outputfile<<ray[i]<<endl;        
        }

	outputfile.close();

	return 0;
}
//Function Name: bubbleSort
//
//Description: Will sort the array passed using bubble sort
//
//Parameters:char* arrayArg[], int raySize
//
//Return Values:None
void bubbleSort(char* arrayArg[], int raySize)
{
	char*temp;
	for(int i = 0; i<raySize; i++)
	{
		for(int j = 0; j < raySize-i-1; j++)
		{
			//if the value of the lower index is greater than the value of the
			//higher index then swap
			if(strcmp(arrayArg[j],arrayArg[j+1])>0)
			{
				temp = arrayArg[j];
                        	arrayArg[j] = arrayArg[j+1];
                        	arrayArg[j+1] = temp;
			}
		}
	}
}
//Function Name: quickSort
//
//Description: Will sort the array passed using quick sort
//
//Parameters:char* arrayArg[], int left, int right
//
//Return Values:None
void quickSort(char* arrayArg[], int left, int right)
{
	int i = left, j = right;
	char* temp;
	//pivot will be the middle element
	char * pivot = arrayArg[(left + right)/2];

	while(i <= j)
	{
		//compare the values at i and j to the pivot and increment i
		//if the value is lower than pivot and decrement j if value is greater than pivot
		while(strcmp(arrayArg[i],pivot)<0)
			i++;
		while(strcmp(arrayArg[j],pivot)>0)
			j--;
		//swap the elements
		if(i <= j)
		{
			temp = arrayArg[i];
			arrayArg[i] = arrayArg[j];
			arrayArg[j] = temp;
			i++;
			j--;
		}
	}
	//recursively called the function with the left and right partitions 
	if(left < j)
		quickSort(arrayArg, left , j);
	if(i < right)
		quickSort(arrayArg, i, right);

}
//Function Name: insertionSort
//
//Description: Will sort the array passed using insertion sort
//
//Parameters:char* arrayArg[], int raySize
//
//Return Values:None
void insertionSort(char* arrayArg[], int raySize)
{
	char* temp;
	for(int i = 0; i < raySize; i++)
	{
		for(int j=i; j > 0 && strcmp(arrayArg[j],arrayArg[j-1])<0; j--)
		{
			//swap the two positions values
			temp = arrayArg[j];
			arrayArg[j] = arrayArg[j-1];
			arrayArg[j-1] = temp;
		}
	}
}
//Function Name: mergeSort
//
//Description: Will sort the array passed using merge sort
//
//Parameters:char* arrayArg[],char* temporary[], int left, int right
//
//Return Values:None
void mergeSort(char* arrayArg[],char* temporary[], int left, int right)
{
	
	int a,b,c;
	int middle = (right+left)/2;
		
	if(left != right)
	{
		//breaking the array down recursively 
		mergeSort(arrayArg, temporary, left, middle);
		mergeSort(arrayArg, temporary, middle+1, right);

		//copy the values to the temp array
		for(a = left; a<=middle; a++)
			temporary[a] = arrayArg[a];
	
		for(b = 1; b <= right-middle; b++)
			temporary[right-b+1]=arrayArg[b+middle];

		//place the values back into the original array in proper order
		a = left;
		b = right;

		for(c = left; c <= right; c++)
		{
			
			if(strcmp(temporary[a], temporary[b])<0)
			{
				arrayArg[c] = temporary[a];
				a++;
			}
			else
			{
				arrayArg[c] = temporary[b];
				b--;
			}
		} 
	}
}
