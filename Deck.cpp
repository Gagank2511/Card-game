#include "Deck.h"
#include <cstdlib>

Deck::Deck(int s) : size(s) {
    cards = new Card*[size];

    for (int i = 0; i < size; i++) {
        int number = (rand() % 13) + 1;
        cards[i] = CardFactory::createCard(number);
    }
}

Card* Deck::drawCard() {
    if (size <= 0) return nullptr;
    return cards[--size];
}

int Deck::getSize() const {
    return size;
}

Deck::~Deck() {
    for (int i = 0; i < size; i++) {
        delete cards[i];
    }
    delete[] cards;
}
