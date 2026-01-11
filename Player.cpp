#include "Player.h"
#include <iostream>
using namespace std;

/*
 * PLAYER CLASS IMPLEMENTATION
 * ---------------------------
 * Demonstrates dynamic memory management and pointer manipulation.
 * This class shows how to implement a resizable array without using std::vector.
 */

Player::Player() : cardCount(0), capacity(10), aceCount(0) {
    /*
     * DYNAMIC MEMORY ALLOCATION:
     * - Allocate initial array of 10 Card pointers on the heap
     * - Using 'new' means we MUST use 'delete' later to prevent memory leak
     */
    hand = new Card*[capacity];
}

void Player::addCard(Card* c) {
    /*
     * DYNAMIC ARRAY RESIZING:
     * When the array is full, we double its capacity.
     * This is similar to how std::vector works internally.
     *
     * Steps:
     * 1. Allocate new larger array
     * 2. Copy existing pointers to new array
     * 3. Delete old array (not the cards themselves!)
     * 4. Update pointer to new array
     */
    if (cardCount >= capacity) {
        int newCapacity = capacity * 2;
        Card** newHand = new Card*[newCapacity];

        // Copy existing card pointers (not the cards themselves)
        for (int i = 0; i < cardCount; i++) {
            newHand[i] = hand[i];
        }

        delete[] hand;  // Delete old array of pointers
        hand = newHand;
        capacity = newCapacity;
    }

    // Track Aces for score calculation
    // Using dynamic_cast to safely check if card is an AceCard
    AceCard* ace = dynamic_cast<AceCard*>(c);
    if (ace != nullptr) {
        aceCount++;
    }

    hand[cardCount++] = c;  // Store the card pointer
}

int Player::getScore() {
    /*
     * ACE HANDLING LOGIC:
     * In Blackjack, Ace can be worth 11 or 1.
     * - Start with Ace = 11
     * - If total > 21 and we have Aces, treat some as 1 instead
     *
     * This demonstrates game logic complexity that requires
     * tracking card types through polymorphism.
     */
    int sum = 0;
    int acesAsEleven = aceCount;  // Initially count all aces as 11

    // Calculate base score
    for (int i = 0; i < cardCount; i++) {
        sum += hand[i]->getValue();
    }

    // Adjust for Aces if busting
    // Each Ace converted from 11 to 1 reduces score by 10
    while (sum > 21 && acesAsEleven > 0) {
        sum -= 10;
        acesAsEleven--;
    }

    return sum;
}

void Player::showHand() {
    cout << "Hand: ";
    for (int i = 0; i < cardCount; i++) {
        cout << hand[i]->getName();
        cout << " (" << hand[i]->getValue() << ")";
        if (i < cardCount - 1) cout << ", ";
    }
    cout << " -> Score: " << getScore() << endl;
}

Player::~Player() {
    /*
     * MEMORY CLEANUP:
     * We own the Card objects, so we must delete them.
     * Then delete the array of pointers itself.
     *
     * Order matters:
     * 1. Delete each Card object the pointers point to
     * 2. Delete the array of pointers
     */
    for (int i = 0; i < cardCount; i++) {
        delete hand[i];  // Delete each Card object
    }
    delete[] hand;  // Delete array of pointers
}
