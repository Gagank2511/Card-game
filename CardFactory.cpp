#include "CardFactory.h"
#include <cstdlib>

Card* CardFactory::createCard(int number) {
    if (number >= 2 && number <= 10)
        return new NormalCard(number, to_string(number));

    int r = rand() % 3;
    if (r == 0) return new FaceCard("Jack");
    if (r == 1) return new FaceCard("Queen");
    return new FaceCard("King");
}
