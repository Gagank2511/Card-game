#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <string>

/*
 * GAME CONFIGURATION STRUCTURE
 * ----------------------------
 * This demonstrates SCALABILITY in C++ code.
 * 
 * WHY USE A CONFIG:
 * - All game settings are in one place (easy to find and change)
 * - We can easily add new settings without changing lots of code
 * - Makes the game customisable
 * - Shows good software design principles
 * 
 * HOW IT WORKS:
 * - We create a struct (like a class but simpler)
 * - It holds all the settings we might want to change
 * - We pass this struct to the Game constructor
 * - Default values are provided so it works out of the box
 */

struct GameConfig {
    // === DECK SETTINGS ===
    int deckSize = 52;              // How many cards in the deck
    int reshuffleThreshold = 10;    // Reshuffle when fewer than this many cards left
    
    // === PLAYER SETTINGS ===
    int startingChips = 100;        // How many chips the player starts with
    int minimumBet = 1;             // Smallest allowed bet
    
    // === DEALER SETTINGS ===
    bool useAggressiveDealer = true;  // true = aggressive, false = conservative
    
    // === DISPLAY SETTINGS ===
    std::string welcomeMessage = "Welcome to Blackjack!";
    bool showDetailedScores = true;   // Show card values in hand display
    
    /*
     * CONSTRUCTOR WITH DEFAULT VALUES:
     * This allows creating a config with all defaults,
     * or customising specific values.
     * 
     * Example usage:
     *   GameConfig config;              // Use all defaults
     *   config.startingChips = 500;     // Change just this one
     *   Game game(config);              // Pass to game
     */
    GameConfig() = default;
};

/*
 * DIFFICULTY PRESETS:
 * These functions return pre-configured GameConfig objects.
 * This shows how we can create different "modes" for the game.
 * 
 * SCALABILITY BENEFIT:
 * Adding a new difficulty is as simple as adding a new function!
 */

// Easy mode - more chips, conservative dealer
inline GameConfig createEasyConfig() {
    GameConfig config;
    config.startingChips = 200;
    config.useAggressiveDealer = false;  // Conservative = easier to beat
    config.welcomeMessage = "Welcome to Blackjack (Easy Mode)!";
    return config;
}

// Normal mode - standard settings
inline GameConfig createNormalConfig() {
    GameConfig config;  // All defaults
    config.welcomeMessage = "Welcome to Blackjack!";
    return config;
}

// Hard mode - fewer chips, aggressive dealer
inline GameConfig createHardConfig() {
    GameConfig config;
    config.startingChips = 50;
    config.useAggressiveDealer = true;  // Aggressive = harder to beat
    config.minimumBet = 5;
    config.welcomeMessage = "Welcome to Blackjack (Hard Mode)!";
    return config;
}

#endif

