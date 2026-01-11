#include "Deck.h"
#include <cstdlib>

/*
 * DECK CLASS IMPLEMENTATION
 * -------------------------
 * This class demonstrates dynamic memory allocation using raw pointers.
 *
 * WHY POINTERS ARE USED HERE:
 * - Card** (pointer to pointer) allows us to create a dynamic array of Card pointers
 * - Each Card* points to a polymorphic Card object (NormalCard, FaceCard, or AceCard)
 * - This enables runtime polymorphism - we can store different card types in one array
 *
 * MEMORY MANAGEMENT:
 * - We allocate memory in the constructor using 'new'
 * - We track both total capacity and current size for proper cleanup
 * - The destructor frees ALL allocated memory to prevent memory leaks
 */

// Array of card suits for realistic deck creation
const string SUITS[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

Deck::Deck(int s) : capacity(s), currentIndex(0) {
    // Dynamically allocate array of Card pointers on the heap
    // This allows the deck size to be determined at runtime
    cards = new Card*[capacity];

    // Use Factory Pattern to create each card
    // The factory returns polymorphic Card* pointers
    for (int i = 0; i < capacity; i++) {
        int number = (rand() % 13) + 1;  // Random card value 1-13
        string suit = SUITS[rand() % 4]; // Random suit
        cards[i] = CardFactory::createCard(number, suit);
    }
}

Card* Deck::drawCard() {
    // Safety check - return nullptr if deck is empty
    if (currentIndex >= capacity) {
        return nullptr;
    }

    // Return pointer to card and move index forward
    // Note: Ownership of the Card transfers to the caller
    // The caller (Player) is now responsible for deleting this card
    return cards[currentIndex++];
}

int Deck::getSize() const {
    // Returns how many cards are left to draw
    return capacity - currentIndex;
}

bool Deck::isEmpty() const {
    return currentIndex >= capacity;
}

Deck::~Deck() {
    /*
     * CRITICAL: Memory cleanup to prevent memory leaks
     *
     * We must delete any cards that were NOT drawn from the deck.
     * Cards that WERE drawn are now owned by Player objects,
     * and will be deleted by Player's destructor.
     *
     * This is an example of "ownership transfer" in C++ memory management.
     */
    for (int i = currentIndex; i < capacity; i++) {
        delete cards[i];  // Delete each remaining Card object
    }
    delete[] cards;  // Delete the array of pointers itself
}
