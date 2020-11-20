#ifndef PLAYER_H
#define PLAYER_H

#include "generic_player.h"

class Player : public Generic_Player {
public:
    Player(const std::string& name = "Player1");
    virtual ~Player();
    virtual bool isHitting() const;
    void Win() const;
    void Lose() const;
    void Push() const;
};
#endif // PLAYER_H
