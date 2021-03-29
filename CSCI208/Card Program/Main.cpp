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

suit switchar(int a);//function to switch the suit index to the corresponding suit variable

int main() {

	srand(time(0));
	int rank, inputRank,inputar,randcard;
	suit mySuit,inputSuit;
	Card deck[52];//array that will contain the deck of cards

	Card test1(0,Spades);//test the card creation by specifically passing variable that we will know the input too
	cout << "TEST 1: the expected output is: Ace of Spades" << endl;
	test1.toString(0);//programmer defined rank index
	Card test2;//tests the default value of the card class
	cout << "TEST 2: the expected output is: Joker" << endl;
	test2.toString(13);//programmer defined rank index of default


	for(int i=0; i<52; i++)
    {
	    inputRank=rand()%13;
	    inputar=(rand()%4)+1;
	    inputSuit=switchar(inputar);
	    Card c2(inputRank,inputSuit);
	    deck[i]=c2;
    }

	randcard=rand()%52;
	cout <<"The random card is: " <<randcard<< endl;
	deck[randcard].toString(deck[randcard].get_rank());

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
suit switchar(int a)
{
  suit place;//dummy suit variable so the suit can be returned
  switch(a)
  {
    case 0: place=Joker;
      break;
    case 1: place=Clubs;
      break;
    case 2: place=Diamonds;
      break;
    case 3: place=Hearts;
      break;
    case 4: place=Spades;
      break;
  }
  return place;//returns the dummy suits newly assigned value
}
