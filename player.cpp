#include "player.h"

Player::Player(const std::string &name) : Generic_Player(name) {}
Player::~Player() {}
void Player::Win() const { std::cout << name << " wins." << std::endl; }
void Player::Lose() const { std::cout << name << " loses." << std::endl; }
void Player:: Push() const {std::cout << name << " pushes." << std::endl; }
bool Player::isHitting() const {
    std::cout << name << ", do you want a hit? (Y/N): ";
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}
