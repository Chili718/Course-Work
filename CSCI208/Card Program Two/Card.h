/*
 *Card.h
 *
 *Jon Tice
 *
 *The header file for the card class
 *
 *
 *CSCI 208
 *
 *9/26/16
 */
#ifndef Card_h
#define Card_h

#include<iostream>
#include<cstring>

using namespace std;

enum suit{Joker,Clubs,Diamonds,Hearts,Spades};

class Card {

	private:
	    //Variables
		int rank;
		suit cardSuit;

		//Setters
		int set_rank(int i);
		suit set_suit(suit cardSuit);

	public:
		//Getters:
		int get_rank();
		suit get_suit();

		//Function to converts to string
		void toString();

		//Constructors:
		Card(int, suit);

		Card();

};
#endif
