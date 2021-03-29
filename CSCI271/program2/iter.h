/*
*Program 2: iter Class File
*
*Jon Tice
*
*The header/implementation file for the iter class
*
*CSCI271
*
*2/18/2018
*/
#ifndef iter_h
#define iter_h
#include "Node.h"

template<class dataType>
class iter
{

	public:
		//Node the iter will be pointing too 
		Node<dataType>* iterPt;
			
		//Constructor
		iter();
		//Destructor
		~iter();
		//Assignment Operator Overloads
		iter& operator=(iter<dataType> dummy);
		iter& operator=(Node<dataType>* dummy);
		iter& operator=(Node<dataType> dummy);
		//Dereference Operator Overload
		dataType operator*();
		//Increment and Decrement Operator Overloads
		iter& operator++();//Prefix
		iter operator++(int);//Postfix
		iter& operator--();//Prefix
                iter operator--(int);//Postfix
		//Equality and Inequality operator overloads
		bool operator==(iter<dataType> dummy);
		bool operator!=(iter<dataType> dummy);
		bool operator==(Node<dataType> dummy);
                bool operator!=(Node<dataType> dummy);		
		
};
//Constructors 
template<class dataType>
iter<dataType>::iter()
{
	iterPt = NULL;	
}
//Destructor 
template<class dataType>
iter<dataType>::~iter()
{
	iterPt = NULL;
	delete iterPt;
}
//Assignment Operator Overloads for iterator, Node, and Node pointer for 
template<class dataType>
iter<dataType>& iter<dataType>::operator=(iter<dataType> dummy)
{
	iterPt = dummy.iterPt;
	return *this;
}

template<class dataType>
iter<dataType>& iter<dataType>::operator=(Node<dataType>* dummy)
{
        iterPt = dummy;
	return *this;
}

template<class dataType>
iter<dataType>& iter<dataType>::operator=(Node<dataType> dummy)
{
        iterPt = &dummy;
        return *this;
}
//Dereference Operator Overload
template<class dataType>
dataType iter<dataType>::operator*()
{
	return this->iterPt->getDataValue();
}
//Prefix ++ operator overload
template<class dataType>
iter<dataType>& iter<dataType>::operator++()
{
	//move iterator to next element then return it
	iterPt = iterPt->getNext();
	return *this;
}
//Postfix ++ operator overload
template<class dataType>
iter<dataType> iter<dataType>::operator++(int)
{
	///return the current iterator position then move it to the next position
	iter<dataType> reterIt = *this;
	iterPt = iterPt->getNext();
        return reterIt;
}

//Prefix -- operator overload
template<class dataType>
iter<dataType>& iter<dataType>::operator--()
{
	//move iterator to previous element then return it
        iterPt = iterPt->getPrevious();
        return *this;
}
//Postfix -- operator overload
template<class dataType>
iter<dataType> iter<dataType>::operator--(int)
{
	//return the current iterator position then move it to the previous position
	iter<dataType> reterIt = *this;
        iterPt = iterPt->getPrevious();
        return reterIt;
}
//Equality and Inequality operator overloads
//Comparing iters to iters and nodes to nodes
template<class dataType>
bool iter<dataType>::operator==(iter<dataType> dummy)
{
        return iterPt == dummy.iterPt;
}

template<class dataType>
bool iter<dataType>::operator!=(iter<dataType> dummy)
{
        return iterPt != dummy.iterPt;
}
//Compparing iters and nodes
template<class dataType>
bool iter<dataType>::operator==(Node<dataType> dummy)
{
        return iterPt == &dummy;
}

template<class dataType>
bool iter<dataType>::operator!=(Node<dataType> dummy)
{
        return iterPt != &dummy;
}


#endif

