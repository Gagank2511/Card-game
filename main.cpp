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
 * - Smart pointers (unique_ptr for automatic memory management)
 * - Move semantics
 * - Lambda functions (functional programming)
 * - Exception handling (try-catch blocks)
 *
 * SCALABILITY:
 * - GameConfig structure for easy customisation
 * - Difficulty presets (Easy, Normal, Hard)
 *
 * Author: Student
 * Module: Advanced Programming
 */

#include "Game.h"
#include "GameConfig.h"  // For game configuration
#include <ctime>
#include <cstdlib>
#include <iostream>

int main() {
    // Seed random number generator for card shuffling
    srand(static_cast<unsigned int>(time(nullptr)));

    /*
     * USING GAMECONFIG FOR SCALABILITY:
     *
     * You can create a game with different settings:
     *
     * Option 1: Default game
     *   Game game;
     *
     * Option 2: Custom config
     *   GameConfig config;
     *   config.startingChips = 500;
     *   Game game(config);
     *
     * Option 3: Use a preset
     *   Game game(createEasyConfig());
     *   Game game(createHardConfig());
     */

    // Using normal (default) configuration
    Game game(createNormalConfig());

    // Start the game
    game.play();

    // Game destructor automatically cleans up all resources
    // (Thanks to smart pointers - no memory leaks!)
    return 0;
}
