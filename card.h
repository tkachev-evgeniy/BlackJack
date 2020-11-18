#ifndef CARD_H
#define CARD_H
#include <iostream>
#include "Ranks.h"


class Card
{
private:
    ranks rank;
    suits suit;
    bool  IsFaceUp;
public:
    void Flip();
    int getValue() const;
    int getRank() const; // не знаю понадобится ли этот метод, но пусть пока живет
    Card(ranks rank, suits suit, bool IsFaceUp);
    friend std::ostream& operator<<(std::ostream& os, const Card& aCard);
};

#endif // CARD_H
