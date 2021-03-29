/*
 *Card.cpp
 *
 *Jon Tice
 *
 *The card class file where the cards functions are expanded upon
 *
 *
 *CSCI 208
 *
 *9/26/16
 */
#ifndef Card_cpp
#define Card_cpp

#include "Card.h"

//Constructors
Card::Card()
{
	rank = 0;
	mySuit = Joker;
}
Card::Card(int inputRank,suit inputSuit)
{
	try
	{
	  if((inputRank<0)||(inputRank>12))
	  {
	    throw 98;
	  }
	}catch (int e){
	    cout << "Invalid Input on Rank! ERROR NUMBER: "<< e <<endl;

	}

	rank=set_rank(inputRank);

	try
	{
	  if((inputSuit<0)||(inputSuit>4))
	  {
	    throw 99;
	  }
	}catch (int e){
	    cout << "Invalid Input on Suit! ERROR NUMBER: "<< e <<endl;

	}

	mySuit=set_suit(inputSuit);
}

//Functions
int Card::get_rank()
{
	return rank;
}
suit Card::get_suit()
{
	return mySuit;
}
void Card::toString(int rank)
{
  string rankAr[14]={"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King",""};


  switch(mySuit)
  {
    case Joker : cout << rankAr[rank] << "Joker" << endl;
      break;
    case Clubs : cout <<rankAr[rank]<< " of Clubs" << endl;
      break;
    case Diamonds : cout <<rankAr[rank]<<" of Diamonds" <<endl;
      break;
    case Hearts : cout <<rankAr[rank]<<" of Hearts" << endl;
      break;
    case Spades: cout <<rankAr[rank]<<" of Spades"<< endl;
      break;

  }

}


int Card::set_rank(int j)
{
	this->rank = j;
	return rank;
}
suit Card::set_suit(suit k)
{
	this->mySuit = k;
	return mySuit;
}
#endif
