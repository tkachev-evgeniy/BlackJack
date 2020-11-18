#ifndef HOUSE_H
#define HOUSE_H

#include "generic_player.h"

class House : public Generic_Player {
public:
    House (const std::string& name = "House");
    virtual ~House();
    virtual bool isHitting() const;
    void FlipFirstCard();
};

#endif // HOUSE_H
