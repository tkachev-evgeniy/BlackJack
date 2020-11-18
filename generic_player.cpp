#include "generic_player.h"

Generic_Player::Generic_Player(const std::string& name) : name(name) {}
Generic_Player::~Generic_Player() {}
bool Generic_Player::isBusted() const { return (GetTotal()>21);}
void Generic_Player::Bust() const {std::cout << name << " busted" << std::endl;}
void Generic_Player::getName() const {std::cout << name << std::endl;}

std::ostream& operator<<(std::ostream& os, const Generic_Player& aGeneric_Player) {
    os<< aGeneric_Player.name << ":\t";
    std::vector<Card*>::const_iterator pCard;
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
