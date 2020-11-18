#include "deck.h"

Deck::Deck()
{
    cards.reserve(52);
    Populate();
}

Deck::~Deck() {} //виртуальный конструктор, ничего не делает, просто отправляет по цепочке наследования выше до класса Hand где происходит очистка памяти.

void Deck::Populate() {
    Clear();
    for (int s = suits::CLUBS; s<= suits::SPADES; ++s ) {
        for (int r = ranks::ACE; r<=ranks::KING; ++r) {
            Add(new Card(static_cast<ranks>(r),static_cast<suits>(s),1));
        }
    }
}

void Deck::Shuffle() {
    std::random_shuffle(cards.begin(),cards.end());
}

void Deck::Deal (Hand& aHand) {
    if (!cards.empty()) {
        aHand.Add(cards.back());
        cards.pop_back();
    }
    else {
        std::cout << "Out of cards. Unable to deal." << std::endl;
    }
}

void Deck::AdditionalCards(Generic_Player &aGenericPlayer) {
    std::cout << std::endl;

    while(!(aGenericPlayer.isBusted())&&aGenericPlayer.isHitting()) {
        Deal(aGenericPlayer);
        std::cout << aGenericPlayer << std::endl;
        if (aGenericPlayer.isBusted()) aGenericPlayer.Bust();
    }
}

