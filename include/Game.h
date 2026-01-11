#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "Strategy.h"
#include "GameConfig.h"  // For game configuration
#include <memory>        // For smart pointers

/*
 * GAME CLASS
 * ----------
 * Orchestrates the card game and manages all game objects.
 *
 * SMART POINTER USAGE:
 * We use std::unique_ptr instead of raw pointers for automatic memory management.
 *
 * WHY SMART POINTERS:
 * - They automatically delete the object when no longer needed
 * - No need to write 'delete' manually (prevents memory leaks)
 * - The code is safer and cleaner
 * - They follow the RAII principle (Resource Acquisition Is Initialisation)
 *
 * UNIQUE_PTR vs SHARED_PTR:
 * - unique_ptr: Only ONE owner (used here because Game owns these objects alone)
 * - shared_ptr: Multiple owners can share the same object
 *
 * FEATURES:
 * - Points-based scoring system
 * - Multiple round support
 * - Score tracking across the game
 *
 * DESIGN CONSIDERATIONS:
 * - Single Responsibility: Game handles game flow, not card/player logic
 * - Composition: Game HAS-A Deck, Player, and Dealer
 */
class Game {
private:
    /*
     * SMART POINTERS:
     * unique_ptr automatically manages memory - no manual delete needed.
     * When Game is destroyed, these objects are automatically cleaned up.
     */
    std::unique_ptr<Deck> deck;       // Smart pointer to deck
    std::unique_ptr<Player> player;   // Smart pointer to player
    std::unique_ptr<Dealer> dealer;   // Smart pointer to dealer

    int playerPoints = 0;
    int dealerPoints = 0;

    GameConfig config;  // Stores all game settings (SCALABILITY)

    // Private helper methods for cleaner code organisation
    void displayWelcome();
    void startRound();
    void dealInitialCards();
    void playerTurn();
    void dealerTurn();
    void determineWinner();
    void resetRound();

public:
    // Default constructor - uses default settings
    Game();

    // Constructor with custom config - allows customisation (SCALABILITY)
    Game(const GameConfig& gameConfig);

    ~Game() = default;  // Smart pointers handle cleanup automatically
    void play();        // Main game loop
};

#endif
