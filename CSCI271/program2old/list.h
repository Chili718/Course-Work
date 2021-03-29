/*
*Program 2: List Class
*
*Jon Tice
*
*The header/implementation file for the doubly linked list class
*
*CSCI 271
*
*2/6/2017
*/
#ifndef list_h
#define list_h

#include"Node.h"
#include"iter.h"

using namespace std;

template<class dataType>
class list
{

	private:
		Node<dataType>* headTemp;
		Node<dataType>* endTemp;
		
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

		dataType& front();
		dataType& back();
	
};

template<class dataType>
list<dataType>::list()
{
	headTemp = new Node<dataType>();
	endTemp = new Node<dataType>();
	(*headTemp).setNext(endTemp);
	(*headTemp).setPrevious(NULL);
	(*endTemp).setNext(NULL);
	(*endTemp).setPrevious(headTemp);
}

template<class dataType>
list<dataType>::list(list<dataType>& toBeCopied)
{
	
}

template<class dataType>
list<dataType>::~list()
{
	clear();
	headTemp = NULL;
	endTemp = NULL;
	delete headTemp;
	delete endTemp;
}

template<class dataType>
void list<dataType>::clear()
{
	if(!empty())
	{
		iter<dataType> del;
		del = (*headTemp).getNext();
		while(del.iterPt != endTemp)
		{
			erase(del);
			del++;
		}
	}
}

template<class dataType>
bool list<dataType>::empty()
{
	if((*headTemp).getNext() == endTemp)
		return true;
	else
		return false;
}

template<class dataType>
int list<dataType>::size()
{
	int sizeL = 0;
	if(!empty())
	{
		iter<dataType> count;
		count = (*headTemp).getNext();
		while(count.iterPt != endTemp)
		{
			sizeL++;
			count++;
		}
		return sizeL;
	}
	else
	{
		return sizeL;
	}
}

template<class dataType>
void list<dataType>::erase(iter<dataType> toBeRemoved)
{
	Node<dataType>* temp;
	Node<dataType>* remove;
	if(toBeRemoved != (*headTemp) && toBeRemoved != (*endTemp))
	{
		remove = toBeRemoved.iterPt;
		temp = (*remove).getNext();
		(*temp).setPrevious((*remove).getPrevious());
		temp = (*remove).getPrevious();
		(*temp).setNext((*remove).getNext());
		remove = NULL;
		delete remove;
	}
}

template<class dataType>
void list<dataType>::push_back(dataType toBeInserted)
{
	Node<dataType>* newEnd = new Node<dataType>(toBeInserted);
	Node<dataType>* insEndNode;
	if(empty())
	{
		(*headTemp).setNext(newEnd);
		(*endTemp).setPrevious(newEnd);
		(*newEnd).setNext(endTemp);
		(*newEnd).setPrevious(headTemp);
	}
	else
	{
		insEndNode = (*endTemp).getPrevious();
		(*insEndNode).setNext(newEnd);
		(*endTemp).setPrevious(newEnd);
		(*newEnd).setNext(endTemp);
		(*newEnd).setPrevious(insEndNode);
		
	}
}

template<class dataType>
void list<dataType>::push_front(dataType toBeInserted)
{
        Node<dataType>* newFront = new Node<dataType>(toBeInserted);
        Node<dataType>* insFrontNode;
        if(empty())
        {
                (*headTemp).setNext(newFront);
                (*endTemp).setPrevious(newFront);
                (*newFront).setNext(endTemp);
                (*newFront).setPrevious(headTemp);
        }
        else
        {
                insFrontNode = (*headTemp).getNext();
                (*insFrontNode).setPrevious(newFront);
                (*headTemp).setNext(newFront);
		(*newFront).setNext(insFrontNode);
		(*newFront).setPrevious(headTemp);

        }
}

template<class dataType>
void list<dataType>::pop_front()
{
	Node<dataType>* poppedFront;
	Node<dataType>* tempFront;
	tempFront = (*poppedFront).getNext();
	poppedFront = (*headTemp).getNext();
	(*headTemp).setNext((*poppedFront).getNext());
	(*tempFront).setPrevious(headTemp);
	poppedFront = NULL;
	delete poppedFront;
}

template<class dataType>
void list<dataType>::pop_back()
{
        Node<dataType>* poppedBack;
	Node<dataType>* tempBack;
	tempBack = (*poppedBack).getPrevious();
        poppedBack = (*endTemp).getPrevious();
        (*endTemp).setPrevious((*poppedBack).getPrevious());
	(*tempBack).setNext(endTemp);
        poppedBack = NULL;
        delete poppedBack;
}

template<class dataType>
iter<dataType> list<dataType>::end()
{
	iter<dataType> endReturn;
	endReturn = endTemp;
	return endReturn;
}

template<class dataType>
iter<dataType> list<dataType>::begin()
{
        iter<dataType> beginReturn;
	beginReturn = (*headTemp).getNext();
        return beginReturn;
}

template<class dataType>
dataType& list<dataType>::front()
{
	iter<dataType> frontIt;
	frontIt = (*headTemp).getNext();
	return &(*frontIt);
}

template<class dataType>
dataType& list<dataType>::back()
{
	int tempBackInt;
	iter<dataType> tempBack;
	tempBack = (*endTemp).getPrevious();
	tempBackInt = (*tempBack);
	return tempBackInt;
}
#endif
