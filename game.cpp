#include "game.h"

Game::Game(const std::vector<std::string> &names)
{
    std::vector<std::string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName) {
        m_Players.push_back(Player(*pName));
    }
    std::srand(static_cast<unsigned int>(std::time(0)));
    m_Deck.Populate();
    m_Deck.Shuffle();
}

void Game::Play() {

    //раздаем всем игрокам и дилеру по две обязательные карты.
    std::vector<Player>::iterator pPlayer;
    for (int i=0; i<2; ++i) {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
            m_Deck.Deal(*pPlayer);
        }
        m_Deck.Deal(m_House);
    }

    m_House.FlipFirstCard();// у дилера одна карта в темную

    //выводим все на экран.
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
        std::cout << *pPlayer << std::endl;
    }
    std::cout << m_House << std::endl;

    //Раздаем карты нуждающимся.
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
        m_Deck.AdditionalCards(*pPlayer);
    }

    //После того как игроки взяли доп. карты, раскрываем первую карту дилера.
    m_House.FlipFirstCard();
    std::cout << m_House << std::endl;

    //После этого даем дилеру возможность взять карты
    m_Deck.AdditionalCards(m_House);

    //Если дилер перебрал, все кто не перебрал раньше побеждают
    //Что то как-то громоздко через итераторы запускать цикл, хочу попробовать подругому.
    if (m_House.isBusted()) {
        for (auto aPlayer : m_Players) {
           if (!(aPlayer.isBusted())) aPlayer.Win();
        }
    }
    else { //иначе сравниваем каждого игрока с дилером
        for (auto aPlayer : m_Players) {
            if (!(aPlayer.isBusted())) {
                if (aPlayer.GetTotal() > m_House.GetTotal()) {
                    aPlayer.Win();
                }
                else if (aPlayer.GetTotal() < m_House.GetTotal()) {
                    aPlayer.Lose();
                }
                else aPlayer.Push();

            }
        }
    }

    //очищаем руки всех игроков.
//    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)    {
//        pPlayer->Clear();
//    }
//    m_House.Clear();
}

Game::~Game() {}
