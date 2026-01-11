#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include "Card.h"
#include <string>

/*
 * CARDFACTORY CLASS
 * -----------------
 * Implements the FACTORY DESIGN PATTERN.
 *
 * PURPOSE:
 * - Centralizes object creation logic in one place
 * - Client code doesn't need to know about specific Card subclasses
 * - Makes it easy to add new card types without changing client code
 *
 * WHY FACTORY PATTERN IS USED:
 * - Encapsulates the complexity of creating different Card types
 * - Returns polymorphic Card* pointers (could be NormalCard, FaceCard, or AceCard)
 * - Follows the Open/Closed Principle - open for extension, closed for modification
 *
 * POINTER USAGE:
 * - Returns Card* because we need polymorphism
 * - Caller becomes responsible for memory cleanup (ownership transfer)
 */
class CardFactory {
public:
    // Static method - no need to instantiate the factory
    // Returns a dynamically allocated Card object
    static Card* createCard(int number, const string& suit);
};

#endif
