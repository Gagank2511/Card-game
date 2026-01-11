cmake_minimum_required(VERSION 3.10)
project(BlackjackGame VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(blackjack
    src/main.cpp
    src/Card.cpp
    src/CardFactory.cpp
    src/Deck.cpp
    src/Game.cpp
    src/Player.cpp
    src/Dealer.cpp
    src/Strategy.cpp
)

# Include directories
target_include_directories(blackjack PUBLIC include)