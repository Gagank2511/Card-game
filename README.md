# Blackjack Card Game

This project implements a simple Blackjack card game in C++. It features classes for cards, decks, players, dealers, and game logic to simulate a basic game of Blackjack.

## Features

- Standard Blackjack rules
- Player and dealer classes
- Deck shuffling and card dealing
- Game configuration options
- Exception handling for game errors

## Prerequisites

- C++ compiler (e.g., Visual Studio, GCC)
- CMake (for building the project)

## Building the Project

1. Ensure you have CMake installed on your system.
2. Navigate to the project directory.
3. Run the following commands:

   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```

This will generate the executable `blackjack.exe` (on Windows) or `blackjack` (on Linux/Mac).

## Running the Game

After building, run the executable:

```bash
./blackjack
```

The game will start and guide you through a simple Blackjack session.

## Project Structure

- `src/`: Source code files (.cpp)
  - `main.cpp`: Entry point of the application.
  - `Card.cpp`: Represents a playing card with suit and rank.
  - `Deck.cpp`: Manages a deck of cards, including shuffling and dealing.
  - `Player.cpp`: Represents a player in the game.
  - `Dealer.cpp`: Represents the dealer.
  - `Game.cpp`: Contains the main game logic.
  - `Strategy.cpp`: Defines strategies for playing.
  - `CardFactory.cpp`: Factory for creating cards.
- `include/`: Header files (.h)
  - `Card.h`: Header for Card class.
  - `Deck.h`: Header for Deck class.
  - `Player.h`: Header for Player class.
  - `Dealer.h`: Header for Dealer class.
  - `Game.h`: Header for Game class.
  - `Strategy.h`: Header for Strategy class.
  - `CardFactory.h`: Header for CardFactory class.
  - `GameConfig.h`: Configuration settings for the game.
  - `GameException.h`: Custom exceptions for the game.
- `CMakeLists.txt`: Build configuration file.
- `README.md`: This file.

## Contributing

Feel free to fork the repository and submit pull requests for improvements or bug fixes.

## Licence

This project is open-source. Please refer to the licence file if included.</content>
<parameter name="filePath">c:\Users\gagan\OneDrive - The Manchester College\Level 6 BSc\Advanced Programming\Part 1\Card game\README.md