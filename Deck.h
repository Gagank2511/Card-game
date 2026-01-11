#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "CardFactory.h"

class Deck {
private:
    Card** cards;
    int size;

public:
    Deck(int s);
    Card* drawCard();
    int getSize() const;
    ~Deck();
};

#endif
