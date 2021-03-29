/*
*Program 2: iter Class File
*
*Jon Tice
*
*The header/implementation file for the iter class
*
*CSCI271
*
*2/1/2017
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
                iter& operator--(int);//Postfix
		//Equality and Inequality operator overloads
		bool operator==(iter<dataType> dummy);
		bool operator!=(iter<dataType> dummy);
		bool operator==(Node<dataType> dummy);
                bool operator!=(Node<dataType> dummy);		
		//makes the list class a friend of this one
		//so list can access iterPt directly
			

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
//Addignment Operator Overloads
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
	iterPt = iterPt->getNext();
	return *this;
}
//Postfix ++ operator overload
template<class dataType>
iter<dataType> iter<dataType>::operator++(int)
{
	iter<dataType> temp = *this;
	iterPt = iterPt->getNext();
        return temp;
}

//Prefix -- operator overload
template<class dataType>
iter<dataType>& iter<dataType>::operator--()
{
        iterPt = iterPt->getPrevious();
        return *this;
}
//Postfix -- operator overload
template<class dataType>
iter<dataType>& iter<dataType>::operator--(int)
{
        iterPt = iterPt->getPrevious();
        return *this;
}
//Equality and Inequality operator overloads
//Comparing iters
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

