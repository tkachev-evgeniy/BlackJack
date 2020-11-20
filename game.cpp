//Если делать все по методичке, то игра может уйти в бесконечный цикл, когда закончатся карты в колоде.
//В ситуации когда дилеру еще нужны карты а колода их дать не может.

//А теперь перепишу циклы по игрокам через for (auto : vector) потому что мне так больше нравится. И хочу научиться так делать.
#include "game.h"

Game::Game(const std::vector<std::string> &names)
{
    for (auto name : names) {
        m_Players.push_back(Player(name));
    }

    unsigned int seed = static_cast<unsigned int>(time(0));
    m_Deck.Shuffle(seed);
}

void Game::Play() {

    for (int i = 0; i < 2; ++i)
    {
        for (auto&& a_Player : m_Players)
        {
            m_Deck.Deal(a_Player);
        }
        m_Deck.Deal(m_House);
    }


    m_House.FlipFirstCard();

    for (auto&& a_Player : m_Players)
    {
        std::cout << a_Player << std::endl;
    }
    std::cout << m_House << std::endl;


    for (auto&& a_Player : m_Players)
    {
        m_Deck.AdditionalCards(a_Player);
    }


    m_House.FlipFirstCard();
    std::cout << std::endl << m_House;


    m_Deck.AdditionalCards(m_House);

    if (m_House.isBusted())
    {

        for (auto&& a_Player : m_Players)
        {
            if (!(a_Player.isBusted()))
            {
                a_Player.Win();
            }
        }
    }
    else
    {

        for (auto&& a_Player : m_Players)
        {
            if (!(a_Player.isBusted()))
            {
                if (a_Player.GetTotal() > m_House.GetTotal())
                {
                    a_Player.Win();
                }
                else if (a_Player.GetTotal() < m_House.GetTotal())
                {
                    a_Player.Lose();
                }
                else
                {
                    a_Player.Push();
                }
            }
        }

    }


    for (auto&& i : m_Players)
    {
        i.Clear();
    }
    m_House.Clear();

}

Game::~Game() {}
