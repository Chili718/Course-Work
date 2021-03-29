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
	cardSuit = Joker;
}
Card::Card(int inpRank,suit inpSuit)
{
	try
	{
	  if((inpRank<0)||(inpRank>12))
	  {
	    throw 55;
	  }
	}catch (int m){

	    cout << "Invalid Rank! ERROR NUMBER: "<< m <<endl;

	}

	rank=set_rank(inpRank);

	try
	{
	  if((inpSuit<0)||(inpSuit>4))
	  {
	    throw 75;
	  }
	}catch (int m){
	    cout << "Invalid Suit! ERROR NUMBER: "<< m <<endl;

	}

	cardSuit=set_suit(inpSuit);
}

/*Function:get_rank
 *
 * Description:Returns the rank of the card object
 *
 * Parameters: None
 *
 * Returns: The rank of the card
 */
int Card::get_rank()
{
	return rank;
}
/*Function:get_suit
 *
 * Description:Returns the suit of the card object
 *
 * Parameters: None
 *
 * Returns: The suit of the card
 */
suit Card::get_suit()
{
	return cardSuit;
}
/*Function:toString
 *
 * Description:Gives the printed name of the card
 *
 * Parameters: None
 *
 * Returns: Nothing
 */
void Card::toString()
{
  string rankSwitch[14]={"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King",""};


  switch(cardSuit)
  {
    case Joker : cout << rankSwitch[rank] << "Joker" << endl;
      break;
    case Clubs : cout <<rankSwitch[rank]<< " of Clubs" << endl;
      break;
    case Diamonds : cout <<rankSwitch[rank]<<" of Diamonds" <<endl;
      break;
    case Hearts : cout <<rankSwitch[rank]<<" of Hearts" << endl;
      break;
    case Spades: cout <<rankSwitch[rank]<<" of Spades"<< endl;
      break;

  }

}
/*Function:set_rank
 *
 * Description:Gives the printed name of the card
 *
 * Parameters: None
 *
 * Returns: Nothing
 */
int Card::set_rank(int j)
{
	this->rank = j;
	return rank;
}
/*Function:set_suit
 *
 * Description:Gives the printed name of the card
 *
 * Parameters: None
 *
 * Returns: Nothing
 */
suit Card::set_suit(suit k)
{
	this->cardSuit = k;
	return cardSuit;
}

#endif
