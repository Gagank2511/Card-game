#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() {
    deck = new Deck(30);
    player = new Player();
    dealer = new Dealer(make_unique<AggressiveStrategy>());
}

Game::~Game() {
    delete deck;
    delete player;
    delete dealer;
}

void Game::play() {
    cout << "===== BLACKJACK LITE =====" << endl;

    player->addCard(deck->drawCard());
    player->addCard(deck->drawCard());
    dealer->addCard(deck->drawCard());

    while (true) {
        cout << "\nYour ";
        player->showHand();

        cout << "\nDealer ";
        dealer->showHand();

        if (player->getScore() > 21) {
            cout << "\nYou busted! Dealer wins.\n";
            return;
        }

        char choice;
        cout << "\nHit or Stand? (h/s): ";
        cin >> choice;

        if (choice == 'h')
            player->addCard(deck->drawCard());
        else 
            break;
    }

    cout << "\n--- Dealer's Turn ---\n";
    while (dealer->shouldDraw()) {
        dealer->addCard(deck->drawCard());
        dealer->showHand();
    }

    int p = player->getScore();
    int d = dealer->getScore();

    cout << "\nFinal Scores - You: " << p << " | Dealer: " << d << endl;

    if (d > 21 || p > d)
        cout << "You win!" << endl;
    else if (p == d)
        cout << "Draw!" << endl;
    else
        cout << "Dealer wins." << endl;
}
