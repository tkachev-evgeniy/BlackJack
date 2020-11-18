#ifndef GENERIC_PLAYER_H
#define GENERIC_PLAYER_H

#include "hand.h"
#include <string>

class Generic_Player : public Hand {
protected:
    std::string name;
public:
    Generic_Player(const std::string& name);
    virtual ~Generic_Player();
    void setName(std::string name);
    void getName() const;
    virtual bool isHitting() const=0;
    bool isBusted() const;
    void Bust() const;
    friend std::ostream& operator<<(std::ostream& os, const Generic_Player& aGeneric_Player);
};

#endif // GENERIC_PLAYER_H
