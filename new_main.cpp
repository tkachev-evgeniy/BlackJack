#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Пусть пока эти энумы полежат вне класса, чтобы были доступны в main, для тестирования.
enum suits{ CLUBS, DIAMONDS, HEARTS, SPADES};
enum ranks{ ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN , KING};

class Card {
private:
    ranks rank;
    suits suit;
    bool  IsFaceUp;

public:
    void Flip();
    int getValue() const;
    int getRank() const; // не знаю понадобится ли этот метод, но пусть пока живет
    Card(ranks rank, suits suit, bool IsFaceUp);
};

void Card::Flip() {IsFaceUp=!(IsFaceUp);}

int Card::getValue() const {return (rank<10?rank+1:10)*IsFaceUp;}

int Card::getRank() const {return rank;}

Card::Card(ranks rank, suits suit, bool IsFaceUp) {
    this->rank = rank;
    this->suit = suit;
    this->IsFaceUp=IsFaceUp;
}



class Hand {
protected:
    vector<Card*> cards;
public:
    Hand();
    virtual ~Hand();
    void Add(Card* newcard);
    void Clear();
    int GetTotal() const;
};

void Hand::Add(Card *newcard) {cards.push_back(newcard);}

void Hand::Clear() {
for (int i=0; i<cards.size(); ++i) {
    delete cards[i];
    cards[i]=0;
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

class Generic_Player : public Hand {
protected:
    string name;
public:
    Generic_Player();
    Generic_Player(string name) : name(name){}
    void setName(string name);
    void getName() const;
    virtual bool isHitting() const;
    bool isBusted() const;
    void Bust() const;
};

bool Generic_Player::isBusted() const { return (this->GetTotal()>21);}
void Generic_Player::Bust() const {cout << name << "busted" << endl;}
void Generic_Player::getName() const {cout << name << endl;}
bool Generic_Player::isHitting() const {return false;} // заглушка;

int main()
{
    {
    Card* C1= new Card(ACE,DIAMONDS,1);
    Card* C2= new Card(JACK,HEARTS,1);
    Card* C3= new Card(TWO,CLUBS,1);
    Hand H1;
    H1.Add(C1);
    H1.Add(C2);
    H1.Add(C3);
    cout << H1.GetTotal() << endl; // убедимся что здесь туз посчитается как 1;

    H1.Clear(); //здесь должны удалиться все три карты переданные в эту руку.
    //Поэтому создадим их заново.

    C1= new Card(ACE,DIAMONDS,1);
    C2= new Card(JACK,HEARTS,0);
    H1.Add(C1);
    H1.Add(C2);
    //Теперь проверим, что в этой руке туз посчитается как 11;
    cout << H1.GetTotal() << endl;
    }
    //Проверим что класс player работает.
    {
    Generic_Player P1("Player1");
    Card* C1= new Card(ACE,DIAMONDS,1);
    Card* C2= new Card(JACK,HEARTS,1);
    Card* C3= new Card(TWO,CLUBS,1);
    P1.getName();
    P1.Add(C1);
    P1.Add(C2);
    P1.Add(C3);
    cout << P1.isBusted() << endl;
    }




}
