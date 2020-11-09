#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum suits{ CLUBS, SPADES, HEARTS, DIAMONDS};
enum ranks{ ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN , KING};

class Card {
protected:

    ranks rank;
    suits suit;
    bool facedown;

public:
    void flip() {facedown=!facedown;}

    int getValue() const {return rank<10?rank+1:10;}
    int getRank() const {return rank;}

    Card(ranks rank, suits suit) {
        this->rank = rank;
        this->suit = suit;
        facedown=false;
    }


};

class Hand {
private:
    vector<Card*> cards;

public:
    void Add(Card* newcard) {
        cards.push_back(newcard);
    }
    void Clear() {
        for (int i=0; i<cards.size(); ++i) {
            delete cards[i];
            //cards[i]=nullptr;
        }
        cards.clear();
    }
    int GetValue() {
        int Value = 0;
        bool haveAce = 0; //Есть ли в руке хотябы один  туз.

        for (int i=0;i<cards.size();++i) {
            if (cards[i]->getValue()==1) haveAce=true; // Если попался туз, ставим пометочку.
            Value = Value + cards[i]->getValue(); // пока считаем туз как единицу
        }
        if ((Value<=11)&haveAce) Value+=10; // Если есть туз, и посчитав его как 11, мы не улетим в перебор, то добавляем 10
        return Value;

    }



};

int main()
{
    Card* C1= new Card(ACE,DIAMONDS);
    Card* C2= new Card(JACK,HEARTS);
    Card* C3= new Card(TWO,CLUBS);
    Hand H1;
    H1.Add(C1);
    H1.Add(C2);
    H1.Add(C3);
    cout << H1.GetValue() << endl; // убедимся что здесь туз посчитается как 1;

    H1.Clear(); //здесь должны удалиться все три карты переданные в эту руку.
    //Поэтому создадим их заново.

    C1= new Card(ACE,DIAMONDS);
    C2= new Card(JACK,HEARTS);
    H1.Add(C1);
    H1.Add(C2);
    //Теперь проверим, что в этой руке туз посчитается как 11;
    cout << H1.GetValue() << endl;








}
