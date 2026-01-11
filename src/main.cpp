/*
 * CARD GAME: BLACKJACK (SCORE-BASED)
 * =================================
 * A console-based card game based on Blackjack rules, demonstrating:
 *
 * MEMORY MANAGEMENT:
 * - Dynamic memory for card handling
 * - Pointer-to-pointer (Card**) for polymorphic storage
 * - Ownership transfer between Deck, Player, and Dealer
 * - Proper cleanup to prevent memory leaks
 *
 * DESIGN PATTERNS:
 * - Factory Pattern (CardFactory): creates different card types
 * - Strategy Pattern (DrawStrategy): interchangeable dealer AI
 *
 * OOP CONCEPTS:
 * - Inheritance (Card hierarchy, Player/Dealer)
 * - Polymorphism (virtual functions for card values)
 * - Encapsulation (private data with public interfaces)
 *
 * MODERN C++:
 * - Smart pointers (unique_ptr for automatic memory management)
 * - Exception handling (try-catch blocks)
 *
 * SCALABILITY:
 * - GameConfig structure for customisable settings
 * - Difficulty presets (Easy, Normal, Hard)
 *
 * DESIGN EVOLUTION:
 * - Earlier versions used betting-style mechanics
 * - Refactored into a score-based card game using points per round
 * - Focuses on accessibility, rule-based play, and general usability
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
     * Option 1: Default game
     *   Game game;
     *
     * Option 2: Custom configuration
     *   GameConfig config;
     *   config.targetScore = 10;
     *   Game game(config);
     *
     * Option 3: Difficulty presets
     *   Game game(createEasyConfig());
     *   Game game(createHardConfig());
     */

    // Using normal (default) configuration
    Game game(createNormalConfig());

    // Start the game
    game.play();

    // Game destructor automatically cleans up all resources
    // (Smart pointers prevent memory leaks)
    return 0;
}
