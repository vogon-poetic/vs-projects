#include <iostream>
#include <ctime>
#include "graph1.h"

class Cards
{
    private:
        int noCards;
        int topCard;
        int* deck;

    public:
        Cards();
        Cards(int noCards);
        ~Cards();
        int getNoCards();
        int dealACard();
        void shuffle();
        void displayCard(int cardNo, int x, int y);
};

Cards::Cards(int noCards)
{
    this->noCards = noCards;
    topCard = 0;
    deck = new int[noCards];
}

Cards::~Cards()
{
    delete[] deck;
}

int Cards::getNoCards()
{
    return noCards;
}

int Cards::dealACard()
{
    if (topCard < noCards)
    { 
        return(deck[topCard++]);
    }
    else
    {
        //Indicate that the deck has been dealt by returning -1
        return -1;
    }
}

void Cards::shuffle()
{
    int i = 0;
    int j = 0;
    bool duplicates = false;

    srand(time(0));
    for (i = 0; i < noCards; i++)
    {
        deck[i] = rand()%noCards + 2;

        do
        {
            //Check for duplicate
            duplicates = false;

            for (j = 0; j < i; j++)
            {
                if (deck[j] == deck[i])
                {
                    deck[i] = rand()%noCards + 2;
                    duplicates = true;
                }
            }
        }while(duplicates);
    }
}

void Cards::displayCard(int cardNo, int x, int y)
{
    //Display hearts for this case
    string fn = "h" + to_string(cardNo) + ".bmp";
    displayBMP(fn, x,y);
}

int main()
{
    //Only process one suit
    int i = 0;
    int x = 100;
    int y = 50;
    int cardNo = 0;
    Cards cards(13);

    displayGraphics();

    //Shuffle the cards
    cards.shuffle();

    //Deal the cards (one at a time)
    for (i = 0; i < cards.getNoCards(); i++)
    {
        //Get the card no from the top
        cardNo = cards.dealACard();

        //Display the card
        cards.displayCard(cardNo,x,y);
        Sleep(1000);
    
        //Increment y
        y += 20;
    }

    return 0;
}
