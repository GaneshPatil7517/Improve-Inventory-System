#include "Player.h"
#include <iostream>

Player::Player(std::string playerName, std::string playerPosition, int playerRating)
    : name(playerName), position(playerPosition), rating(playerRating), fatigue(0) {}

void Player::performPlay() {
    std::cout << name << " is performing a play!" << std::endl;
    fatigue += 5;
}

void Player::updateStats(int statChange) {
    rating += statChange;
}
