#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "CardFactory.h"

/*
 * DECK CLASS
 * ----------
 * Manages a collection of Card pointers using dynamic memory allocation.
 *
 * POINTER USAGE JUSTIFICATION:
 * - Uses Card** to store polymorphic Card objects
 * - Enables storing different card types (NormalCard, FaceCard, AceCard) together
 * - Dynamic allocation allows deck size to be set at runtime
 */
class Deck {
private:
    Card** cards;       // Pointer to array of Card pointers (dynamic array)
    int capacity;       // Total number of cards created
    int currentIndex;   // Index of next card to draw

public:
    Deck(int s);
    Card* drawCard();       // Returns ownership of card to caller
    int getSize() const;    // Cards remaining
    bool isEmpty() const;   // Check if deck is empty
    ~Deck();                // Cleans up remaining cards
};

#endif
