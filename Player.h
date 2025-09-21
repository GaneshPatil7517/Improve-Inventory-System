#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    std::string position;
    int rating;
    int fatigue;

public:
    Player(std::string playerName, std::string playerPosition, int playerRating);
    void performPlay();
    void updateStats(int statChange);
};

#endif
