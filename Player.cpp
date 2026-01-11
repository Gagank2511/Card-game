#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() : cardCount(0), capacity(10) {
    hand = new Card*[capacity];
}

void Player::addCard(Card* c) {
    if (cardCount >= capacity) {
        int newCapacity = capacity * 2;
        Card** newHand = new Card*[newCapacity];

        for (int i = 0; i < cardCount; i++)
            newHand[i] = hand[i];

        delete[] hand;
        hand = newHand;
        capacity = newCapacity;
    }

    hand[cardCount++] = c;
}

int Player::getScore() {
    int sum = 0;
    for (int i = 0; i < cardCount; i++)
        sum += hand[i]->getValue();
    return sum;
}

void Player::showHand() {
    cout << "Hand: ";
    for (int i = 0; i < cardCount; i++) {
        cout << hand[i]->getName() 
             << "(" << hand[i]->getValue() << ") ";
    }
    cout << " -> Score: " << getScore() << endl;
}

Player::~Player() {
    for (int i = 0; i < cardCount; i++)
        delete hand[i];

    delete[] hand;
}
