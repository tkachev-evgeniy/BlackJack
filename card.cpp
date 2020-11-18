#include "card.h"

void Card::Flip() {IsFaceUp=!(IsFaceUp);}

int Card::getValue() const {return (rank<10?rank:10)*IsFaceUp;}

int Card::getRank() const {return rank;}

std::ostream& operator<<(std::ostream& os, const Card& aCard) {
    const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const std::string SUITS[] = { "c", "d", "h", "s" };

    if (aCard.IsFaceUp)
    {
        os << RANKS[aCard.rank] << SUITS[aCard.suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}

Card::Card(ranks rank, suits suit, bool IsFaceUp) {
    this->rank = rank;
    this->suit = suit;
    this->IsFaceUp=IsFaceUp;
}

