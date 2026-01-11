/*
 * BLACKJACK CARD GAME
 * ===================
 * A console-based Blackjack game demonstrating:
 *
 * MEMORY MANAGEMENT:
 * - Dynamic arrays for hand management
 * - Pointer-to-pointer (Card**) for polymorphic storage
 * - Proper cleanup to prevent memory leaks
 * - Ownership transfer between Deck and Player
 *
 * DESIGN PATTERNS:
 * - Factory Pattern (CardFactory) - creates different card types
 * - Strategy Pattern (DrawStrategy) - interchangeable dealer AI
 *
 * OOP CONCEPTS:
 * - Inheritance (Card hierarchy, Player/Dealer)
 * - Polymorphism (virtual functions for card values)
 * - Encapsulation (private data, public interface)
 *
 * MODERN C++:
 * - Smart pointers (unique_ptr for Strategy)
 * - Move semantics
 *
 * Author: Student
 * Module: Advanced Programming
 */

#include "Game.h"
#include <ctime>
#include <cstdlib>

int main() {
    // Seed random number generator for card shuffling
    srand(static_cast<unsigned int>(time(nullptr)));

    // Create game object on the stack
    // Game internally manages heap-allocated objects
    Game game;

    // Start the game
    game.play();

    // Game destructor automatically cleans up all resources
    return 0;
}
