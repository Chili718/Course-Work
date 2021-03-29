/*
*Program 0: Test Main
*
*Jon Tice
*
*The test main for the linked list class
*
*CSCI271
*
*1/8/2018
*/
#include "ticej_LinkedList_p0.h"
#include<cstring>
using namespace std;

int main()
{
	LinkedList<int> listy;
	LinkedList<string> listy2;
	//testing insert in order and size with listy2
	listy2.insert_in_order("avery");
        listy2.insert_in_order("zolton");
        listy2.insert_in_order("max");	
	listy2.insert_in_order("alvy");
	listy2.insert_in_order("charlvy");
	listy2.insert_in_order("bronson");
	
	cout<<"The names should be in alphabetical order: "<<endl;

	listy2.print_all();

        cout<<"The size of the list is: "<<listy2.size()<<endl;
	//testing the push front, back, and size on listy
	listy.push_front(3);
	listy.push_front(2);
	listy.push_front(1);
	listy.push_front(0);
	listy.push_back(4);
	listy.push_back(5);

	cout<<"The numbers should be in order: "<<endl;

	listy.print_all();
	//testing pop and size functions
	cout<<"The size of the list is: "<<listy.size()<<endl;

	listy.pop_front();
	listy.pop_front();
	listy.pop_back();

	cout<<"Should not contain 1, 5, or 0."<<endl;

	listy.print_all();

	cout<<"The size of the list is: "<<listy.size()<<endl;
	//removing all items in the list 
	listy.pop_back();
	listy.pop_back();
	listy.pop_front();

	cout<<"Should be empty."<<endl;

	listy.print_all();

	cout<<"The size of the list is: "<<listy.size()<<endl;
	//testing insert in order and size again with listy	
	cout<<"The numbers should be in order: "<<endl;

	listy.insert_in_order(5);
        listy.insert_in_order(90);
        listy.insert_in_order(1);
        listy.insert_in_order(7);
        listy.insert_in_order(3);
        listy.insert_in_order(5);
        listy.insert_in_order(32);
        listy.insert_in_order(6);
        listy.insert_in_order(2);

	listy.print_all();

        cout<<"The size of the list is: "<<listy.size()<<endl;

	return 0;
}
