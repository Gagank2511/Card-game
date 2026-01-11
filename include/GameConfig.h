#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <string>

/*
 * GAME CONFIGURATION STRUCTURE
 * ----------------------------
 * Stores settings in one place to make the game easy to customise.
 */

struct GameConfig {
    // === DECK SETTINGS ===
    int deckSize = 52;              // How many cards in the deck
    int reshuffleThreshold = 10;    // Recreate deck when fewer than this many cards remain

    // === SCORE SETTINGS ===
    int targetScore = 5;            // First to this many points wins

    // === DEALER SETTINGS ===
    bool useAggressiveDealer = true;  // true = aggressive, false = conservative

    // === DISPLAY SETTINGS ===
    std::string welcomeMessage = "Welcome to the Card Game: Blackjack (Score Mode)";
    bool showDetailedScores = true;

    GameConfig() = default;
};

/*
 * DIFFICULTY PRESETS
 */

inline GameConfig createEasyConfig() {
    GameConfig config;
    config.targetScore = 3;
    config.useAggressiveDealer = false;
    config.welcomeMessage = "Welcome to the Card Game: Blackjack (Easy Mode)";
    return config;
}

inline GameConfig createNormalConfig() {
    GameConfig config;
    config.targetScore = 5;
    config.useAggressiveDealer = false; // optional: normal can be conservative
    config.welcomeMessage = "Welcome to the Card Game: Blackjack (Normal Mode)";
    return config;
}

inline GameConfig createHardConfig() {
    GameConfig config;
    config.targetScore = 7;
    config.useAggressiveDealer = true;
    config.welcomeMessage = "Welcome to the Card Game: Blackjack (Hard Mode)";
    return config;
}

#endif
