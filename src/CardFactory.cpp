#include "CardFactory.h"
#include <cstdlib>

/*
 * CARDFACTORY IMPLEMENTATION
 * --------------------------
 * Factory Design Pattern - creates appropriate Card subclass based on input.
 *
 * MEMORY ALLOCATION:
 * - Uses 'new' to allocate Card objects on the heap
 * - Returns pointer to caller who becomes the owner
 * - Caller is responsible for calling 'delete' when done
 */

Card* CardFactory::createCard(int number, const string& suit) {
    /*
     * Card creation logic:
     * - 1 = Ace (special card worth 1 or 11)
     * - 2-10 = Normal cards (worth face value)
     * - 11 = Jack, 12 = Queen, 13 = King (all worth 10)
     *
     * The 'new' keyword allocates memory on the heap.
     * We return a base class pointer (Card*) but the actual
     * object is a derived type - this is POLYMORPHISM.
     */

    if (number == 1) {
        // Ace - special card with dual value
        return new AceCard();
    }
    else if (number >= 2 && number <= 10) {
        // Normal numbered cards
        string cardName = to_string(number) + " of " + suit;
        return new NormalCard(number, cardName);
    }
    else if (number == 11) {
        return new FaceCard("Jack of " + suit);
    }
    else if (number == 12) {
        return new FaceCard("Queen of " + suit);
    }
    else {
        return new FaceCard("King of " + suit);
    }
}
