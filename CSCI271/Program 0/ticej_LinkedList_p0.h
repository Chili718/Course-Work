/*
*Program 0: Linked List Class File
*
*Jon Tice
*
*The header/implementation file for the LinkedList class
*
*CSCI271
*
*1/8/2018
*/

#ifndef LinkedList_h
#define LinkedList_h
#include<iostream>
#include<stddef.h>

using namespace std;

//this linked list is doubly linked with a next and previous 
//pointer for each node
template<class E>
struct Node{
	Node<E> * previous;
	E dataVal;
	Node<E> * next;	
};

template<class E>
class LinkedList
{
	private:
		Node<E>* head;
		Node<E>* tail;
	public:
		//constructor 
		LinkedList();
		//functions to insert
		void push_front(E item);
		void push_back(E item);
		void insert_in_order(E item);
		//functions to remove items
		E pop_front();
		E pop_back();
		//functions for size and printing all elements
		int size();
		void print_all();

};
//Constructor 
template<class E>
LinkedList<E>::LinkedList()
{
	//create head and tail node
	head = new Node<E>();
	tail = new Node<E>();
	tail->previous = head;
	tail->next = NULL;
	head->previous = NULL;
	head->next = tail;
}
/*
*Function Name:push_front
*
*Description:Inserts the item passed into the linked list from the front
*
*Parameters:E item
*
*Return Value:None
*/
template<class E>
void LinkedList<E>::push_front(E item)
{
	//create the new node and assign the value passed to it
	Node<E>* insertF = new Node<E>();
	insertF->dataVal = item;
	//change the pointers to insert at the front
	insertF->next = head->next;
	head->next->previous = insertF;
	head->next = insertF;
	insertF->previous = head;
	
}
/*
*Function Name:push_back
*
*Description:Inserts the item passed into the linked list from the back
*
*Parameters:E item
*
*Return Value:None
*/
template<class E>
void LinkedList<E>::push_back(E item)
{
	//create the new node and assign the value passed to it
        Node<E>* insertB = new Node<E>();
        insertB->dataVal = item;
	//change the pointers to insert at the front
        insertB->next = tail;
        insertB->previous = tail->previous;
        tail->previous->next = insertB;
	tail->previous = insertB;

}
/*
*Function Name:insert_in_order
*
*Description:Inserts the item passed into the linked list in its proper place to maintain order
*
*Parameters:E item
*
*Return Value:None
*/
template<class E>
void LinkedList<E>::insert_in_order(E item)
{
	//create the node that will be inserted and the node that will be at the
	//position to insert it
	Node<E>* order = head->next;
	Node<E>* insertOrder = new Node<E>();
	insertOrder->dataVal = item;
	//move through the list to find where the node will be inserted
	while(order != tail && item >= order->dataVal)
	{
		order = order->next;
	}
	//insert the node in its proper position
	insertOrder->next = order;
	insertOrder->previous = order->previous;
	order->previous->next = insertOrder;
	order->previous = insertOrder;
}
/*
*Function Name:print_all
*
*Description:Prints the values of each node in the linked list starting at the front
*
*Parameters:None
*
*Return Value:None
*/
template<class E>
void LinkedList<E>::print_all()
{
	Node<E>* current = head->next;
	
	while(current != tail)
	{
		//print the value and move to the next node
		cout<<current->dataVal<<endl;
		current = current->next;
	}
}
/*
*Function Name:size
*
*Description:Returns the number of elements in the linked list
*
*Parameters:None
*
*Return Value:int (The size of the list)
*/
template<class E>
int LinkedList<E>::size()
{
	int count = 0;
	Node<E>* current = head->next;
	//move through the list counting each node until the tail is reached
        while(current != tail)
        {
                count++;
		current = current->next;
        }
	return count;
}
/*
*Function Name:pop_front
*
*Description:Removes the first node from the linked list and returns its value
*
*Parameters:None
*
*Return Value:E (The data value of the node being popped)
*/
template<class E>
E LinkedList<E>::pop_front()
{
	Node<E>* popF = head->next;
	E data = popF->dataVal;
	//change the pointers so the node is no longer in the list
	popF->next->previous = head;
	head->next = popF->next;	
	//delete the node
	delete popF;

	return data;
}
/*
*Function Name:pop_back
*
*Description:Removes the last node from the linked list and returns its value
*
*Parameters:None
*
*Return Value:E (The data value of the node being popped)
*/
template<class E>
E LinkedList<E>::pop_back()
{
	Node<E>* popB = tail->previous;
        E data = popB->dataVal;
	//change the pointers so the node is no longer in the list
        popB->previous->next = tail;
        tail->previous = popB->previous;
	//delete the node
        delete popB;

        return data;
}
#endif
