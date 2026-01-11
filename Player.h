#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

class Player {
protected:
    Card** hand;
    int cardCount;
    int capacity;

public:
    Player();
    void addCard(Card* c);
    int getScore();
    void showHand();
    virtual ~Player();
};

#endif
