#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "Strategy.h"

class Game {
private:
    Deck* deck;
    Player* player;
    Dealer* dealer;

public:
    Game();
    ~Game();
    void play();
};

#endif
