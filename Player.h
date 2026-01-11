#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

/*
 * PLAYER CLASS
 * ------------
 * Manages a player's hand of cards using dynamic memory allocation.
 *
 * POINTER AND MEMORY MANAGEMENT DEMONSTRATION:
 * - Uses Card** (pointer to pointer) for a resizable dynamic array
 * - Implements manual array resizing when capacity is exceeded
 * - Takes ownership of Card* pointers received from Deck
 * - Responsible for deleting Card objects in destructor
 *
 * WHY RAW POINTERS HERE:
 * - Demonstrates understanding of manual memory management
 * - Shows dynamic array implementation without std::vector
 * - Educational purpose - understanding what happens "under the hood"
 *
 * SCALABILITY:
 * - Array automatically doubles in size when full
 * - Can handle any number of cards
 */
class Player {
protected:
    Card** hand;        // Dynamic array of Card pointers
    int cardCount;      // Current number of cards in hand
    int capacity;       // Current array capacity
    int aceCount;       // Track aces for score calculation

public:
    Player();
    void addCard(Card* c);      // Takes ownership of the Card
    int getScore();             // Calculates score with Ace logic
    void showHand();            // Displays all cards
    virtual ~Player();          // Virtual for proper inheritance cleanup
};

#endif
