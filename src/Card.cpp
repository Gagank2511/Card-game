#include "Card.h"

/*
 * CARD CLASS IMPLEMENTATIONS
 * --------------------------
 * Demonstrates inheritance and polymorphism through different card types.
 * Each card type calculates its value differently.
 */

// ============== BASE CARD CLASS ==============
Card::Card(int v, string n) : value(v), name(n) {
    // Initializer list is more efficient than assignment in body
}

Card::~Card() {
    // Virtual destructor ensures derived class destructors are called
    // when deleting through a base class pointer
}

// ============== NORMAL CARD (2-10) ==============
NormalCard::NormalCard(int v, string n) : Card(v, n) {
    // Passes value and name to base class constructor
}

int NormalCard::getValue() const {
    return value;  // Returns the face value (2-10)
}

string NormalCard::getName() const {
    return name;
}

// ============== FACE CARD (Jack, Queen, King) ==============
FaceCard::FaceCard(string n) : Card(10, n) {
    // Face cards always worth 10 in Blackjack
}

int FaceCard::getValue() const {
    return 10;  // Fixed value for all face cards
}

string FaceCard::getName() const {
    return name;
}

// ============== ACE CARD (Special: 1 or 11) ==============
AceCard::AceCard() : Card(11, "Ace") {
    // Default value is 11, but can be treated as 1 if needed
    // The Player class handles the logic of when to use 1 vs 11
}

int AceCard::getValue() const {
    return value;  // Returns 11 by default
}

string AceCard::getName() const {
    return "Ace";
}

bool AceCard::isAce() const {
    return true;  // Used to identify Aces for score calculation
}
