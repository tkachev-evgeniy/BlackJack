#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Пусть пока эти энумы полежат вне класса, чтобы были доступны в main, для тестирования.
enum suits{ CLUBS, DIAMONDS, HEARTS, SPADES};
enum ranks{ ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN , KING};

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
    friend ostream& operator<<(ostream& os, const Card& aCard);
};

void Card::Flip() {IsFaceUp=!(IsFaceUp);}

int Card::getValue() const {return (rank<10?rank:10)*IsFaceUp;}

int Card::getRank() const {return rank;}

ostream& operator<<(ostream& os, const Card& aCard) {
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };

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
    Generic_Player(const string& name);
    virtual ~Generic_Player();
    void setName(string name);
    void getName() const;
    virtual bool isHitting() const=0;
    bool isBusted() const;
    void Bust() const;
    friend ostream& operator<<(ostream& os, const Generic_Player& aGeneric_Player);
};
Generic_Player::Generic_Player(const string& name) : name(name) {}
Generic_Player::~Generic_Player() {}
bool Generic_Player::isBusted() const { return (GetTotal()>21);}
void Generic_Player::Bust() const {cout << name << " busted" << endl;}
void Generic_Player::getName() const {cout << name << endl;}


ostream& operator<<(ostream& os, const Generic_Player& aGeneric_Player) {
    os<< aGeneric_Player.name << ":\t";
    vector<Card*>::const_iterator pCard;
    if (!aGeneric_Player.cards.empty()) {
        for (pCard = aGeneric_Player.cards.begin();
             pCard != aGeneric_Player.cards.end();
             ++pCard) {
            os<<*(*pCard) <<"\t";
        }
        if (aGeneric_Player.GetTotal()!=0) {
            os << "(" << aGeneric_Player.GetTotal() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }
    return os;
}

class Player : public Generic_Player {
public:
    Player(const string& name = "Player1");
    virtual ~Player();
    virtual bool isHitting() const;
    void Win() const;
    void Lose() const;
    void Push() const;
};

Player::Player(const string &name) : Generic_Player(name) {}
Player::~Player() {}
void Player::Win() const { cout << name << " wins." << endl; }
void Player::Lose() const { cout << name << " loses." << endl; }
void Player:: Push() const {cout << name << " pushes." << endl; }
bool Player::isHitting() const {
    cout << name << ", do you want a hit? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}


class House : public Generic_Player {
public:
    House (const string& name = "House");
    virtual ~House();
    virtual bool isHitting() const;
    void FlipFirstCard();
};

House :: House(const string &name) : Generic_Player(name) {}
House :: ~House() {}
bool House::isHitting() const { return (GetTotal()<=16); }
void House::FlipFirstCard() {
    if (!(cards.empty())) cards[0]->Flip();
    else cout << "No card to flip!" << endl;
}



int main()
{
    // Потестируем новые классы и методы.
    Player P1("High Roller");
    cout << P1;

    Card* C1= new Card(ACE,DIAMONDS,1);
    Card* C2= new Card(JACK,HEARTS,1);
    Card* C3= new Card(TWO,CLUBS,1);

    P1.Add(C1);
    cout << P1 << endl;

    P1.Add(C2);
    cout << P1 << endl;

    P1.Add(C3);
    cout << P1 << endl;

    cout << boolalpha << P1.isHitting() << endl;
    cout << "Player busted - " << P1.isBusted() << endl;
    P1.Win();
    P1.Lose();
    P1.Bust();
    P1.Push();


    P1.Clear();

    C1= new Card(ACE,DIAMONDS,0);
    C2= new Card(JACK,HEARTS,1);
    C3= new Card(TWO,CLUBS,1);

    House H;
    H.Add(C1);
    cout << H << endl;
    H.Add(C2);
    cout << H << endl;

    H.Add(C3);
    cout << H << endl;

    H.FlipFirstCard();
    cout << H << endl;

    cout << "House is hitting - " << H.isHitting() << endl;
    cout << "House busted - " << H.isBusted()<< endl;
    H.Bust();




}
