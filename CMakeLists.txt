cmake_minimum_required(VERSION 3.10)
project(BlackjackGame VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(blackjack
    main.cpp
    Card.cpp
    CardFactory.cpp
    Deck.cpp
    Game.cpp
    Player.cpp
    Dealer.cpp
    Strategy.cpp
)

# Include directories
target_include_directories(blackjack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})