/*
*Program 2: Node Class File
*
*Jon Tice
*
*The header/implementation file for the node class
*
*CSCI271
*
*2/1/2017
*/
#ifndef Node_h
#define Node_h

#include<stddef.h>


template<class dataType>
class Node
{
	private:
		dataType value;
		Node<dataType>* next;
		Node<dataType>* previous;
	public:
		//Constructors
		Node();
		Node(dataType typeOf);
		Node(dataType typeOf, Node<dataType>* nextN, Node<dataType>* previousN);
		//Setters
		void setDataType(dataType valueToBe);
		void setNext(Node<dataType>* nextToBe);
		void setPrevious(Node<dataType>* previousToBe);
		//Getters
		Node<dataType>* getNext();
		Node<dataType>* getPrevious();
		dataType getDataValue();
		//Destructor
		~Node();
};

//Constructors
template<class dataType>
Node<dataType>::Node()
{
	next = NULL;
	previous = NULL;
}

template<class dataType>
Node<dataType>::Node(dataType typeOf)
{
	value = typeOf;
        next = NULL;
        previous = NULL;
}

template<class dataType>
Node<dataType>::Node(dataType typeOf, Node<dataType>* nextN, Node<dataType>* previousN)
{
        value = typeOf;
        next = nextN;
        previous = previousN;
}

//Set Functions
template<class dataType>
void Node<dataType>::setDataType(dataType valueToBe)
{
	value = valueToBe;
}

template<class dataType>
void Node<dataType>::setNext(Node<dataType>* nextToBe)
{
	next = nextToBe;
}

template<class dataType>
void Node<dataType>::setPrevious(Node<dataType>* previousToBe)
{
	previous = previousToBe;
}

//Get Functions 
template<class dataType>
Node<dataType>* Node<dataType>::getNext()
{
	return next;
}

template<class dataType>
Node<dataType>* Node<dataType>::getPrevious()
{
        return previous;
}

template<class dataType>
dataType Node<dataType>::getDataValue()
{
        return value;
}

template<class dataType>
Node<dataType>::~Node()
{
	next = NULL;
        previous = NULL;
	delete next;
	delete previous;
}
#endif
