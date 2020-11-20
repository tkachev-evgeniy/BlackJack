#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "house.h"
#include "player.h"
#include <ctime>

class Game
{

private:
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;

public:
    Game(const std::vector<std::string> &names);
    ~Game();
    void Play();
};

#endif // GAME_H
