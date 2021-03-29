/*
 *Main
 *
 *Jon Tice
 *
 *Creates a deck of 52 cards and outputs a random card from the deck
 *
 *
 *CSCI 208
 *
 *9/26/16
 */
#include<iostream>
#include "Card.h"//includes our predefined header file for the card class
#include<cstring>
#include<cstdlib>
#include<ctime>

using namespace std;

suit numToSuit(int placeHold);//function to switch the suit index to the corresponding suit variable

int main() {

	srand(time(0));
	int inputRank,enterSuit;
	suit inputSuit;
	Card deck[52];//array that will contain the deck of cards


	Card test1(0,Spades);//test the card creation by specifically passing variable that we will know the input too
	cout << "TEST 1: the expected output is: Ace of Spades" << endl;
	test1.toString();//programmer defined rank index
	Card test2;//tests the default value of the card class
	cout << "TEST 2: the expected output is: Joker" << endl;
	test2.toString();//programmer defined rank index of default


	for(int i=0; i<52; i++)
    {
	    enterRank=rand()%13;

	    inputRank=(rand()%4)+1;

	    inputSuit=numToSuit(enterSuit);

	    Card newCard(enterRank,inputSuit);

	    deck[i]=newCard;
    }

	return 0;
}
/*Function:switchar
 *
 * Description:Is passed the integer index of the suits and outputs the corresponding suit variable
 *
 * Parameters: The integer of the index of the suit
 *
 * Returns: The corresponding suit of the index integer
 */
suit numToSuit(int placeHold)
{
  suit dummy;//dummy suit variable so the suit can be returned

  switch(placeHold)
  {
    case 0: dummy = Joker;
      break;
    case 1: dummy = Clubs;
      break;
    case 2: dummy = Diamonds;
      break;
    case 3: dummy = Hearts;
      break;
    case 4: dummy = Spades;
      break;
  }

  return dummy;//returns the dummy suits newly assigned value

}
