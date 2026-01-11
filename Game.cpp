#include "Game.h"
#include "GameException.h"  // For custom exceptions
#include <iostream>
#include <limits>
using namespace std;

/*
 * GAME CLASS IMPLEMENTATION
 * -------------------------
 * Main game controller that coordinates all game objects.
 * Demonstrates pointer management and object composition.
 *
 * SCALABILITY:
 * The game now uses GameConfig to store all settings.
 * This makes it easy to customise the game without changing this code.
 */

// Default constructor - uses default config
Game::Game() : Game(GameConfig()) {
    // This calls the other constructor with a default GameConfig
    // This pattern is called "constructor delegation"
}

// Constructor with custom config
Game::Game(const GameConfig& gameConfig)
    : config(gameConfig),                    // Store the config
      playerChips(gameConfig.startingChips), // Use config values
      currentBet(0) {
    /*
     * SMART POINTER CREATION WITH make_unique:
     *
     * make_unique<Type>(args) creates a unique_ptr that owns a new object.
     * This is safer than 'new' because:
     * - Memory is automatically freed when the pointer goes out of scope
     * - No need to remember to call 'delete'
     * - Exception-safe (won't leak memory if an exception is thrown)
     */

    // Create deck using config setting
    deck = make_unique<Deck>(config.deckSize);
    player = make_unique<Player>();

    // Create Dealer with strategy based on config
    // This shows how config makes the game SCALABLE and CUSTOMISABLE
    if (config.useAggressiveDealer) {
        dealer = make_unique<Dealer>(make_unique<AggressiveStrategy>());
    } else {
        dealer = make_unique<Dealer>(make_unique<ConservativeStrategy>());
    }
}

/*
 * DESTRUCTOR - Now empty!
 *
 * With smart pointers, we don't need to manually delete anything.
 * When Game is destroyed, the unique_ptrs automatically delete their objects.
 * This is called RAII (Resource Acquisition Is Initialisation).
 *
 * The destructor is set to '= default' in the header file.
 */

void Game::displayWelcome() {
    cout << "\n========================================" << endl;
    cout << "       " << config.welcomeMessage << endl;  // Use config message
    cout << "========================================" << endl;
    cout << "Try to get as close to 21 as possible!" << endl;
    cout << "Face cards = 10, Ace = 1 or 11" << endl;
    cout << "You start with " << config.startingChips << " chips." << endl;
    cout << "========================================\n" << endl;
}

void Game::placeBet() {
    cout << "\nYou have " << playerChips << " chips." << endl;
    cout << "Place your bet (" << config.minimumBet << "-" << playerChips << "): ";

    // Input validation loop - uses config.minimumBet
    while (!(cin >> currentBet) || currentBet < config.minimumBet || currentBet > playerChips) {
        cout << "Invalid bet! Enter a number between " << config.minimumBet
             << " and " << playerChips << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Bet placed: " << currentBet << " chips.\n" << endl;
}

void Game::dealInitialCards() {
    // Deal two cards to player, one to dealer (standard Blackjack opening)
    player->addCard(deck->drawCard());
    player->addCard(deck->drawCard());
    dealer->addCard(deck->drawCard());
}

void Game::playerTurn() {
    char choice;

    while (true) {
        cout << "\nYour ";
        player->showHand();

        cout << "Dealer shows: ";
        dealer->showHand();

        // Check for bust
        if (player->getScore() > 21) {
            cout << "\n*** BUST! You went over 21! ***" << endl;
            return;
        }

        // Check for Blackjack (21 with 2 cards)
        if (player->getScore() == 21) {
            cout << "\n*** BLACKJACK! ***" << endl;
            return;
        }

        cout << "\n[H]it or [S]tand? ";
        cin >> choice;

        if (choice == 'h' || choice == 'H') {
            /*
             * EXCEPTION HANDLING WITH TRY-CATCH:
             * We wrap the drawCard() call in a try block because it might throw
             * an EmptyDeckException. If it does, we catch it and handle it nicely.
             */
            try {
                Card* newCard = deck->drawCard();  // This might throw an exception
                cout << "You drew: " << newCard->getName() << endl;
                player->addCard(newCard);
            }
            catch (const EmptyDeckException& e) {
                // Catch the exception and display a friendly message
                cout << "Sorry! " << e.what() << endl;
                cout << "You must stand." << endl;
                break;
            }
        } else {
            cout << "You stand with " << player->getScore() << "." << endl;
            break;
        }
    }
}

void Game::dealerTurn() {
    cout << "\n-------- DEALER'S TURN --------" << endl;

    while (dealer->shouldDraw() && !deck->isEmpty()) {
        /*
         * TRY-CATCH FOR DEALER'S DRAW:
         * Same exception handling as player's turn.
         * If deck is empty, dealer must stop drawing.
         */
        try {
            Card* newCard = deck->drawCard();
            cout << "Dealer draws: " << newCard->getName() << endl;
            dealer->addCard(newCard);
            dealer->showHand();
        }
        catch (const EmptyDeckException& e) {
            cout << "Deck is empty - dealer must stand." << endl;
            break;  // Exit the loop
        }
    }

    if (dealer->getScore() > 21) {
        cout << "*** Dealer BUSTS! ***" << endl;
    } else {
        cout << "Dealer stands with " << dealer->getScore() << "." << endl;
    }
}

void Game::determineWinner() {
    int playerScore = player->getScore();
    int dealerScore = dealer->getScore();

    cout << "\n======== RESULTS ========" << endl;
    cout << "Your Score:   " << playerScore << endl;
    cout << "Dealer Score: " << dealerScore << endl;
    cout << "=========================" << endl;

    if (playerScore > 21) {
        cout << "You busted! Dealer wins." << endl;
        playerChips -= currentBet;
    }
    else if (dealerScore > 21) {
        cout << "Dealer busted! YOU WIN!" << endl;
        playerChips += currentBet;
    }
    else if (playerScore > dealerScore) {
        cout << "YOU WIN!" << endl;
        playerChips += currentBet;
    }
    else if (playerScore == dealerScore) {
        cout << "It's a PUSH (tie). Bet returned." << endl;
        // No chips gained or lost
    }
    else {
        cout << "Dealer wins." << endl;
        playerChips -= currentBet;
    }

    cout << "\nChips remaining: " << playerChips << endl;
}

void Game::resetRound() {
    /*
     * RESETTING FOR NEW ROUND WITH SMART POINTERS:
     *
     * With unique_ptr, we use 'reset()' to replace the object.
     * reset() does two things:
     * 1. Deletes the old object automatically
     * 2. Takes ownership of a new object
     *
     * This is much cleaner than manual delete + new!
     */

    // Reset player for new round
    player.reset(new Player());

    // Reset dealer using config setting (SCALABILITY)
    if (config.useAggressiveDealer) {
        dealer.reset(new Dealer(make_unique<AggressiveStrategy>()));
    } else {
        dealer.reset(new Dealer(make_unique<ConservativeStrategy>()));
    }

    // Recreate deck if below threshold (using config)
    if (deck->getSize() < config.reshuffleThreshold) {
        deck.reset(new Deck(config.deckSize));
    }
}

void Game::play() {
    displayWelcome();

    char playAgain;

    // Main game loop - supports multiple rounds
    do {
        // Check if player has chips
        if (playerChips <= 0) {
            cout << "\n*** You're out of chips! Game Over. ***" << endl;
            break;
        }

        placeBet();
        dealInitialCards();
        playerTurn();

        // Only do dealer's turn if player didn't bust
        if (player->getScore() <= 21) {
            dealerTurn();
        }

        determineWinner();

        if (playerChips > 0) {
            cout << "\nPlay another round? (y/n): ";
            cin >> playAgain;

            if (playAgain == 'y' || playAgain == 'Y') {
                resetRound();
            }
        }

    } while ((playAgain == 'y' || playAgain == 'Y') && playerChips > 0);

    cout << "\n========================================" << endl;
    cout << "Thanks for playing!" << endl;
    cout << "Final chip count: " << playerChips << endl;
    cout << "========================================" << endl;
}
