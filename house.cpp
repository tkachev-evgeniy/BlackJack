#include "house.h"

House :: House(const std::string &name) : Generic_Player(name) {}
House :: ~House() {}
bool House::isHitting() const { return (GetTotal()<=16); }
void House::FlipFirstCard() {
    if (!(cards.empty())) cards[0]->Flip();
    else std::cout << "No card to flip!" << std::endl;
}
