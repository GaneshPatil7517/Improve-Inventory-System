#ifndef FEATURE_CLASSES_H
#define FEATURE_CLASSES_H

#include <string>
#include <vector>

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

class Play {
private:
    std::string type;
    std::string formation;
    Player* playerInvolved;

public:
    Play(std::string playType, std::string playFormation, Player* player);
    void execute();
    int calculateSuccess();
};

class AIManager {
private:
    std::string defensiveStrategy;
    std::string offensiveStrategy;
    int adaptationLevel;

public:
    AIManager();
    void analyzePlayerMoves();
    void adjustDefense();
    void adjustOffense();
};

class GameManager {
private:
    int currentScore;
    int gameTime;
    std::vector<Player*> players;

public:
    GameManager();
    void startGame();
    void updateScore();
    void checkPlayPattern();
};

#endif // FEATURE_CLASSES_H
