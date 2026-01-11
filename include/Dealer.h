#ifndef DEALER_H
#define DEALER_H

#include "Player.h"
#include "Strategy.h"
#include <memory>

/*
 * DEALER CLASS
 * ------------
 * Inherits from Player and uses Strategy Pattern for decision making.
 *
 * DESIGN PATTERNS USED:
 * 1. INHERITANCE - Dealer IS-A Player, reuses hand management
 * 2. STRATEGY PATTERN - Delegates draw decisions to a strategy object
 *
 * SMART POINTER USAGE:
 * - Uses std::unique_ptr for DrawStrategy ownership
 * - unique_ptr automatically deletes the strategy when Dealer is destroyed
 * - Demonstrates modern C++ memory management (RAII principle)
 *
 * WHY UNIQUE_PTR:
 * - Dealer has exclusive ownership of its strategy
 * - No need for manual delete - automatic cleanup
 * - Cannot be copied (enforces single ownership)
 * - Can be moved (ownership transfer)
 */
class Dealer : public Player {
private:
    // Smart pointer manages strategy lifetime automatically
    std::unique_ptr<DrawStrategy> strategy;

public:
    // Takes ownership of strategy via move semantics
    Dealer(std::unique_ptr<DrawStrategy> s);

    // Delegates decision to strategy object
    bool shouldDraw();
};

#endif
