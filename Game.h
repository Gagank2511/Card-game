#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "Strategy.h"

/*
 * GAME CLASS
 * ----------
 * Orchestrates the Blackjack game and manages all game objects.
 *
 * POINTER USAGE:
 * - Uses raw pointers for Deck, Player, and Dealer objects
 * - Demonstrates ownership and lifetime management
 * - Game is responsible for creating and destroying these objects
 *
 * FEATURES:
 * - Betting system with chips for realism and originality
 * - Multiple round support
 * - Score tracking across rounds
 *
 * DESIGN CONSIDERATIONS:
 * - Single Responsibility: Game handles game flow, not card/player logic
 * - Composition: Game HAS-A Deck, Player, and Dealer
 */
class Game {
private:
    Deck* deck;         // Pointer to the deck of cards
    Player* player;     // Pointer to the human player
    Dealer* dealer;     // Pointer to the AI dealer

    int playerChips;    // Player's current chip count
    int currentBet;     // Current round's bet amount

    // Private helper methods for cleaner code organization
    void displayWelcome();
    void placeBet();
    void dealInitialCards();
    void playerTurn();
    void dealerTurn();
    void determineWinner();
    void resetRound();

public:
    Game();
    ~Game();
    void play();        // Main game loop
};

#endif
