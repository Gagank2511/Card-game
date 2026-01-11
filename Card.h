#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

/*
 * CARD CLASS HIERARCHY
 * --------------------
 * Demonstrates INHERITANCE and POLYMORPHISM in C++.
 *
 * DESIGN PATTERN: Template Method Pattern
 * - Base class defines interface (getValue, getName)
 * - Derived classes provide specific implementations
 *
 * WHY POLYMORPHISM IS USED:
 * - Allows treating all card types uniformly through Card* pointers
 * - Enables runtime binding - correct getValue() called based on actual object type
 * - Makes it easy to add new card types without changing existing code
 *
 * WHY VIRTUAL DESTRUCTOR:
 * - Essential when deleting derived objects through base class pointers
 * - Ensures proper cleanup of derived class resources
 */

// Abstract base class - cannot be instantiated directly
class Card {
protected:
    int value;      // Point value of the card
    string name;    // Display name (e.g., "5", "King", "Ace")

public:
    Card(int v, string n);

    // Pure virtual functions make this class abstract
    // Each derived class MUST implement these
    virtual int getValue() const = 0;
    virtual string getName() const = 0;

    // Virtual destructor for proper polymorphic deletion
    virtual ~Card();
};

/*
 * NORMALCARD CLASS
 * ----------------
 * Represents numbered cards (2-10).
 * Value equals the card number.
 */
class NormalCard : public Card {
public:
    NormalCard(int v, string n);
    int getValue() const override;
    string getName() const override;
};

/*
 * FACECARD CLASS
 * --------------
 * Represents Jack, Queen, King.
 * All face cards have fixed value of 10 in Blackjack.
 */
class FaceCard : public Card {
public:
    FaceCard(string n);
    int getValue() const override;
    string getName() const override;
};

/*
 * ACECARD CLASS
 * -------------
 * Special card that can be worth 1 OR 11.
 * This is a key feature of Blackjack strategy.
 * Player class handles the dual-value logic.
 */
class AceCard : public Card {
public:
    AceCard();
    int getValue() const override;  // Returns 11 by default
    string getName() const override;
    bool isAce() const;             // Identifies this as an Ace
};

#endif
