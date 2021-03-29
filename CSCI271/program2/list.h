/*
*Program 2: List Class
*
*Jon Tice
*
*The header/implementation file for the doubly linked list class
*
*CSCI 271
*
*2/18/2018
*/
#ifndef list_h
#define list_h

#include"iter.h"

using namespace std;

template<class dataType>
class list
{

	private:
		Node<dataType>* headTemp;
		Node<dataType>* endTemp;
		//int to keep track of the number of elements in the list
		int sze;
	public:
		
		//Constructor
		list();
		//Copy Constructor
		list(list<dataType>& toBeCopied);
		//Destructor
		~list();

		void clear();		
		
		bool empty();

		int size();

		void erase(iter<dataType> toBeRemoved);

		void push_back(dataType toBeInserted);
		void push_front(dataType toBeInserted);

		void pop_front();
		void pop_back();

		iter<dataType> end();
		iter<dataType> begin();

		dataType front();
		dataType back();

		list& operator=(list<dataType>& toBeCopied);
	
};
//Constructor 
template<class dataType>
list<dataType>::list()
{
	headTemp = new Node<dataType>();
	endTemp = new Node<dataType>();
	(*headTemp).setNext(endTemp);
	(*headTemp).setPrevious(NULL);
	(*endTemp).setNext(NULL);
	(*endTemp).setPrevious(headTemp);
	sze = 0;
}
//Copy Constructor using the overloaded = operator
template<class dataType>
list<dataType>::list(list<dataType>& toBeCopied)
{
	headTemp = new Node<dataType>();
        endTemp = new Node<dataType>();
        (*headTemp).setNext(endTemp);
        (*headTemp).setPrevious(NULL);
        (*endTemp).setNext(NULL);
        (*endTemp).setPrevious(headTemp);
	sze = 0;
	*this = toBeCopied;
}
//Destructor
template<class dataType>
list<dataType>::~list()
{
	clear();
	headTemp = NULL;
	endTemp = NULL;
	delete headTemp;
	delete endTemp;
}
/*
*Name:clear
*
*Description:Removes all of the items from the list thus making the list empty
*
*Parameters:None
*
*Return Value(s):None
*/
template<class dataType>
void list<dataType>::clear()
{
	if(!empty())
	{
		iter<dataType> del, delB;
		del = (*headTemp).getNext();
		while(del.iterPt != endTemp)
		{
			delB = del;
			erase(delB);
			del++;
		}
		sze = 0;
	}
}
/*
*Name:empty
*
*Description:Retruns a true boolean value if the list is empty and false if not
*
*Parameters:None
*
*Return Value(s):bool
*/
template<class dataType>
bool list<dataType>::empty()
{
	if(sze == 0)
		return true;
	else
		return false;
}
/*
*Name:size
*
*Description:Returns the number of elements in the list
*
*Parameters:None
*
*Return Value(s):sze
*/
template<class dataType>
int list<dataType>::size()
{
	return sze;
}
/*
*Name:erase
*
*Description:Removes the item indicated by the iterator from the list
*
*Parameters:iter<dataType> toBeRemoved
*
*Return Value(s):None
*/
template<class dataType>
void list<dataType>::erase(iter<dataType> toBeRemoved)
{
	Node<dataType>* temp;
	Node<dataType>* remove;
	//the head and end temp nodes are not to be removed
	if(toBeRemoved != *headTemp && toBeRemoved != *endTemp)
	{  
		remove = toBeRemoved.iterPt;
		temp = (*remove).getNext();
		(*temp).setPrevious((*remove).getPrevious());
		temp = (*remove).getPrevious();
		(*temp).setNext((*remove).getNext());

		remove = NULL;
		delete remove;
	}
	sze--;
}
/*
*Name:push_back
*
*Description:Inserts the item passed into the back of the list
*
*Parameters:dataType toBeInserted
*
*Return Value(s):None
*/
template<class dataType>
void list<dataType>::push_back(dataType toBeInserted)
{
	Node<dataType>* newEnd = new Node<dataType>(toBeInserted);
	
	(*newEnd).setNext(endTemp);
	(*newEnd).setPrevious((*endTemp).getPrevious());
	endTemp->getPrevious()->setNext(newEnd);
	(*endTemp).setPrevious(newEnd);
		
	sze++;
}
/*
*Name:push_front
*
*Description:Inserts the item pased into the front of the list
*
*Parameters:dataType toBeInserted
*
*Return Value(s):None
*/
template<class dataType>
void list<dataType>::push_front(dataType toBeInserted)
{
        Node<dataType>* newFront = new Node<dataType>(toBeInserted);
        
        (*newFront).setNext((*headTemp).getNext());
        (*newFront).setPrevious(headTemp);
        headTemp->getNext()->setPrevious(newFront);
        (*headTemp).setNext(newFront);

	sze++;
}
/*
*Name:pop_front
*
*Description:Removes the first element of the list from the list
*
*Parameters:None
*
*Return Value(s):None
*/
template<class dataType>
void list<dataType>::pop_front()
{
	Node<dataType>* poppedFront = (*headTemp).getNext();
	Node<dataType>* newFront = (*poppedFront).getNext();

	(*headTemp).setNext(newFront);
	(*newFront).setPrevious(headTemp);
	
	poppedFront = NULL;
	delete poppedFront;
	sze--;
}
/*
*Name:pop_back
*
*Description:Removes the last element of the list from the list
*
*Parameters:None
*
*Return Value(s):None
*/
template<class dataType>
void list<dataType>::pop_back()
{
        Node<dataType>* poppedBack = (*endTemp).getPrevious();
	Node<dataType>* newBack = (*poppedBack).getPrevious();

	(*newBack).setNext(endTemp);
        (*endTemp).setPrevious(newBack);
	
        poppedBack = NULL;
        delete poppedBack;
	sze--;
}
/*
*Name:end
*
*Description:Returns an iterator to the past the end element in the list(endTemp)
*
*Parameters:None
*
*Return Value(s):endReturn - an iterator to the past the end element
*/
template<class dataType>
iter<dataType> list<dataType>::end()
{
	iter<dataType> endReturn;
	endReturn = endTemp;
	return endReturn;
}
/*
*Name:begin
*
*Description:Returns an iterator to the first element in the list
*
*Parameters:None
*
*Return Value(s):beginReturn - the iterator to the first element in the list
*/
template<class dataType>
iter<dataType> list<dataType>::begin()
{
        iter<dataType> beginReturn;
	beginReturn = (*headTemp).getNext();
        return beginReturn;
}
/*
*Name:operator=
*
*Description:Overloaded assignment operator that allows us to copy a list with ease
*
*Parameters:list<dataType>& toBeCopied
*
*Return Value(s):list<dataType>& - the modified list on the left of the operator
*/
template<class dataType>
list<dataType>& list<dataType>::operator=(list<dataType>& toBeCopied)
{
	//removes all items from the current list
	clear();
	//move through the pushing all the elements to be copied into the list
	for(iter<dataType> i = toBeCopied.begin(); i != toBeCopied.end(); ++i)
        {
                push_back(*i);
	}
	//obtain the size from the list being copied
	this->sze = toBeCopied.size();
}
/*
*Name:front
*
*Description:Returns the data of the first element in the list.
*
*Parameters:None
*
*Return Value(s):*frontIt - The data of the first element in the list
*/
template<class dataType>
dataType list<dataType>::front()
{
	iter<dataType> frontIt;
	frontIt = (*headTemp).getNext();
	return *frontIt;
}
/*
*Name:back
*
*Description:Returns the data of the last element in the list
*
*Parameters:None
*
*Return Value(s):backIt - the data of the last element in the list
*/
template<class dataType>
dataType list<dataType>::back()
{
	iter<dataType> backIt;
	backIt = (*endTemp).getPrevious();
	return *backIt;
}
#endif
