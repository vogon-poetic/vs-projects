#include <iostream>
#include <string>
#include "graph1.h"
#include "CardPlayer.h"

CardPlayer::CardPlayer()
{
	//Implement the default Constructor
	setColor('r');
	setNoCards(0);
	hand = NULL;
}

CardPlayer::~CardPlayer()
{
	delete[] hand;
}

void CardPlayer::setNoCards(int noCards)
{
	if (noCards < 5) {
		this->noCards = 5;
	}
	else if (noCards > 10) {
		this->noCards = 10;
	}
	else {
		this->noCards = noCards;
	}

	this->hand = new int[this->noCards];
}

int CardPlayer::getNoCards()
{
	return(this->noCards);
}

void CardPlayer::setColor(char color)
{
	this->color = color;
}

void CardPlayer::displayHand(int x, int y)
{
	string suit;
	if (this->color == 'r') {
		suit = "d";
	}
	else {
		suit = "s";
	}
	for (int i = 0; i < this->noCards; ++i) {
		displayBMP(suit + to_string(i + 2) + ".bmp", x, (y + 20 * i));
	}
}

int CardPlayer::computeScore()
{
	int score = 0;
	for (int i = 0; i < this->noCards; ++i) {
		if (this->hand[i] == 11 ||
			this->hand[i] == 12 ||
			this->hand[i] == 13) {
			score += 10;
		} else if (this->hand[i] == 14) {
			score += 11;
		} else {
			score += this->hand[i];
		}
	}

	return score;
}

//Implemented for you
void CardPlayer::deal()
{
	bool duplicate = false;


	for (int i = 0; i < noCards; i++) {
		hand[i] = rand() % 13 + 2;

		do {
			duplicate = false;
			for (int j = 0; j < i; j++) {
				if (hand[i] == hand[j]) {
					hand[i] = rand() % 13 + 2;
					duplicate = true;
					break;
				}
			}
		} while (duplicate);
	}
}

