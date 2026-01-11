#include "Game.h"
#include <iostream>
#include <limits>
using namespace std;

/*
 * GAME CLASS IMPLEMENTATION
 * -------------------------
 * Main game controller that coordinates all game objects.
 * Demonstrates pointer management and object composition.
 */

// Starting chips for the player
const int STARTING_CHIPS = 100;

Game::Game() : playerChips(STARTING_CHIPS), currentBet(0) {
    /*
     * DYNAMIC OBJECT CREATION:
     * - All game objects are created on the heap using 'new'
     * - Game class owns these objects (responsible for deletion)
     * - Pointers allow polymorphism (Dealer is-a Player)
     */
    deck = new Deck(52);    // Standard deck size
    player = new Player();

    // Create Dealer with AggressiveStrategy using smart pointer
    dealer = new Dealer(make_unique<AggressiveStrategy>());
}

Game::~Game() {
    /*
     * CLEANUP - Following RAII principle:
     * Game owns these objects, so Game must delete them.
     * Order doesn't matter here as they don't depend on each other.
     */
    delete deck;
    delete player;
    delete dealer;
}

void Game::displayWelcome() {
    cout << "\n========================================" << endl;
    cout << "       BLACKJACK - CARD GAME" << endl;
    cout << "========================================" << endl;
    cout << "Try to get as close to 21 as possible!" << endl;
    cout << "Face cards = 10, Ace = 1 or 11" << endl;
    cout << "You start with " << STARTING_CHIPS << " chips." << endl;
    cout << "========================================\n" << endl;
}

void Game::placeBet() {
    cout << "\nYou have " << playerChips << " chips." << endl;
    cout << "Place your bet (1-" << playerChips << "): ";

    // Input validation loop
    while (!(cin >> currentBet) || currentBet < 1 || currentBet > playerChips) {
        cout << "Invalid bet! Enter a number between 1 and " << playerChips << ": ";
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
            Card* newCard = deck->drawCard();
            if (newCard != nullptr) {
                cout << "You drew: " << newCard->getName() << endl;
                player->addCard(newCard);
            } else {
                cout << "Deck is empty!" << endl;
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
        Card* newCard = deck->drawCard();
        if (newCard != nullptr) {
            cout << "Dealer draws: " << newCard->getName() << endl;
            dealer->addCard(newCard);
            dealer->showHand();
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
     * MEMORY MANAGEMENT FOR NEW ROUND:
     * - Delete old player and dealer (they own their cards)
     * - Create fresh player and dealer for new round
     * - Recreate deck if running low on cards
     */
    delete player;
    delete dealer;

    player = new Player();
    dealer = new Dealer(make_unique<AggressiveStrategy>());

    // Recreate deck if less than 10 cards remain
    if (deck->getSize() < 10) {
        delete deck;
        deck = new Deck(52);
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
