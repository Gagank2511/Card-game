#include "Dealer.h"

/*
 * DEALER CLASS IMPLEMENTATION
 * ---------------------------
 * Demonstrates Strategy Pattern and Smart Pointer usage.
 */

Dealer::Dealer(std::unique_ptr<DrawStrategy> s)
    : strategy(std::move(s)) {
    /*
     * MOVE SEMANTICS:
     * - std::move transfers ownership of the unique_ptr
     * - After this, the original pointer is null
     * - Dealer now owns the strategy exclusively
     *
     * This is more efficient than copying and ensures
     * there's only one owner of the strategy object.
     */
}

bool Dealer::shouldDraw() {
    /*
     * STRATEGY PATTERN IN ACTION:
     * - Dealer doesn't know which strategy is being used
     * - Calls the interface method shouldDraw()
     * - Polymorphism ensures the correct implementation runs
     *
     * This allows changing dealer behavior without modifying this code.
     */
    return strategy->shouldDraw(getScore());
}
