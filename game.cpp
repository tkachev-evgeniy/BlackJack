//Если делать все по методичке, то игра может уйти в бесконечный цикл, когда закончатся карты в колоде.
//В ситуации когда дилеру еще нужны карты а колода их дать не может.
#include "game.h"

Game::Game(const std::vector<std::string> &names)
{
    for (auto i : names) {
        m_Players.push_back(Player(i));
    }

    unsigned int seed = static_cast<unsigned int>(time(0));
    m_Deck.Shuffle(seed);
}

void Game::Play() {

    std::vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            m_Deck.Deal(*pPlayer);
        }
        m_Deck.Deal(m_House);
    }


    m_House.FlipFirstCard();

    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        std::cout << *pPlayer << std::endl;
    }
    std::cout << m_House << std::endl;


    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        m_Deck.AdditionalCards(*pPlayer);
    }


    m_House.FlipFirstCard();
    std::cout << std::endl << m_House;


    m_Deck.AdditionalCards(m_House);

    if (m_House.isBusted())
    {

        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            if (!(pPlayer->isBusted()))
            {
                pPlayer->Win();
            }
        }
    }
    else
    {

        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
             ++pPlayer)
        {
            if (!(pPlayer->isBusted()))
            {
                if (pPlayer->GetTotal() > m_House.GetTotal())
                {
                    pPlayer->Win();
                }
                else if (pPlayer->GetTotal() < m_House.GetTotal())
                {
                    pPlayer->Lose();
                }
                else
                {
                    pPlayer->Push();
                }
            }
        }

    }


    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        pPlayer->Clear();
    }
    m_House.Clear();

}

Game::~Game() {}
