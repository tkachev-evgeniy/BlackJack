#ifndef HAND_H
#define HAND_H
#include <vector>
#include "card.h"


class Hand
{
protected:
    std::vector<Card*> cards;
public:
    Hand();
    virtual ~Hand();
    void Add(Card* newcard);
    void Clear();
    int GetTotal() const;
};

#endif // HAND_H
