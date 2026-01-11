#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include "Card.h"

class CardFactory {
public:
    static Card* createCard(int number);
};

#endif
