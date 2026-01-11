#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <exception>
#include <string>

/*
 * CUSTOM EXCEPTION CLASSES
 * ------------------------
 * These classes demonstrate exception handling in C++.
 * 
 * WHY USE EXCEPTIONS:
 * - They separate error handling from normal code flow
 * - They make the code cleaner and easier to read
 * - They allow errors to be caught at the appropriate level
 * 
 * HOW IT WORKS:
 * - We inherit from std::exception (the base exception class)
 * - We override the what() method to provide an error message
 * - We throw these exceptions when something goes wrong
 * - We catch them in the Game class to handle errors gracefully
 */

// Exception thrown when trying to draw from an empty deck
class EmptyDeckException : public std::exception {
private:
    std::string message;  // Stores the error message

public:
    // Constructor - takes an error message
    EmptyDeckException(const std::string& msg = "The deck is empty!")
        : message(msg) {}

    // Override what() to return our custom message
    // This is called when we catch the exception
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Exception thrown when player runs out of points
class OutOfPointsException : public std::exception {
private:
    std::string message;

public:
    OutOfPointsException(const std::string& msg = "You have run out of points!")
        : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Exception thrown when an invalid round is started
class InvalidRoundException : public std::exception {
private:
    std::string message;

public:
    InvalidRoundException(const std::string& msg = "Invalid round start!")
        : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif

