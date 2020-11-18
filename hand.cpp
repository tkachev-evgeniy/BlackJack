#include "hand.h"

void Hand::Add(Card *newcard) {cards.push_back(newcard);}

void Hand::Clear() {
    std::vector<Card*>::iterator iter = cards.begin();
    for (iter = cards.begin(); iter != cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    cards.clear();
}

int Hand::GetTotal() const{
    int Total= 0;
    bool haveAce = 0; //Есть ли в руке хотябы один  туз.
    for (int i=0;i<cards.size();++i) {
        if ((cards[i]->getValue()==1)) haveAce=true; // Если попался туз, ставим пометочку.
        Total = Total + cards[i]->getValue(); // пока считаем туз как единицу
    }
    if ((Total<=11)&&haveAce) Total+=10; // Если есть туз, и посчитав его как 11, мы не улетим в перебор, то добавляем 10
    return Total;}

Hand::~Hand() {Clear();}

Hand::Hand() {cards.reserve(7);}
