/*
*Homework: What happens when you go past the end of an STL Linked List?
*
*Jon Tice
*
*The test program that shows what happens when you iterate past the end
*of a STL linkeed list.
*
*CSCI271
*
*1/8/2018
*/
#include<iostream>
#include<list>

using namespace std;

int main()
{
	list <char> testList;
	list<char>::iterator testIter;
	//populate the list with some elements 
	testList.push_back('a');
	testList.push_back('b');
	testList.push_back('c');
	//the iterator will be at the past_the_end element in the list container
	testIter = testList.end();

	//cout<<testIter<<endl;

	//incrementing the iterator to the next element
	testIter++;

	//after the initial test the iterator went to the first element in the list (a)
	//when you iterate to the next element past the past_the_end element the STL Linked List you are returned
	//to the first element in the list

	cout<<"This will print the first element in the list(a): "<<endl; 
	cout<<*testIter<<endl;
	
	//if we move back through the list twice we should be at the last element in the list
	//decrementing the iterator to the previous element (past_the_end element)
	testIter--;
	//and again to get to the last element in the list containing a value
	testIter--;

	cout<<"This will be the last element in the list (c)"<<endl;
        cout<<*testIter<<endl;

	//this shows the list is circular linked list

	return 0;
}
