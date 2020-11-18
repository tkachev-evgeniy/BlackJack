#include "deck.h"

Deck::Deck()
{
    cards.reserve(52);
    Populate();
}

Deck::~Deck() {} //виртуальный деструктор, ничего не делает, просто отправляет по цепочке наследования выше до класса Hand где происходит очистка памяти.

void Deck::Populate() {
    Clear();
    for (int s = suits::CLUBS; s<= suits::SPADES; ++s ) {
        for (int r = ranks::ACE; r<=ranks::KING; ++r) {
            Add(new Card(static_cast<ranks>(r),static_cast<suits>(s),1));
        }
    }
}

void Deck::Shuffle(unsigned int seed) {
    std::shuffle(cards.begin(),cards.end(),std::default_random_engine(seed));
}

bool Deck::Deal (Hand& aHand) {
    if (!cards.empty()) {
        aHand.Add(cards.back());
        cards.pop_back();
        return cards.empty();
    }
    else {
        std::cout << "Out of cards. Unable to deal." << std::endl;
        return cards.empty();
    }
}

void Deck::AdditionalCards(Generic_Player &aGenericPlayer) {
    std::cout << std::endl;

    while(!(aGenericPlayer.isBusted())&&aGenericPlayer.isHitting()&&(!(cards.empty()))) { // здесь может образоваться бесконечный цикл если House готов принять карты
        Deal(aGenericPlayer);                                         // а в колоде карт больше нет, поэтому добавлю проверку не пустая ли колода
        std::cout << aGenericPlayer << std::endl;
        if (aGenericPlayer.isBusted()) aGenericPlayer.Bust();
    }
}

