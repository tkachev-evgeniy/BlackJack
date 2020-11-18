#ifndef DECK_H
#define DECK_H

#include <random>
#include "hand.h"
#include "generic_player.h"

class Deck : public Hand
{
public:
    Deck();

    virtual ~Deck();

    void Populate();

    void Shuffle();

    void Deal(Hand& aHand);

    void AdditionalCards(Generic_Player& aGenericPlayer);
};

#endif // DECK_H
