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

- `Card.h` / `Card.cpp`: Represents a playing card with suit and rank.
- `Deck.h` / `Deck.cpp`: Manages a deck of cards, including shuffling and dealing.
- `Player.h` / `Player.cpp`: Represents a player in the game.
- `Dealer.h` / `Dealer.cpp`: Represents the dealer.
- `Game.h` / `Game.cpp`: Contains the main game logic.
- `Strategy.h` / `Strategy.cpp`: Defines strategies for playing.
- `CardFactory.h` / `CardFactory.cpp`: Factory for creating cards.
- `GameConfig.h`: Configuration settings for the game.
- `GameException.h`: Custom exceptions for the game.
- `main.cpp`: Entry point of the application.
- `CMakeLists.txt`: Build configuration file.

## Contributing

Feel free to fork the repository and submit pull requests for improvements or bug fixes.

## Licence

This project is open-source. Please refer to the licence file if included.</content>
<parameter name="filePath">c:\Users\gagan\OneDrive - The Manchester College\Level 6 BSc\Advanced Programming\Part 1\Card game\README.md