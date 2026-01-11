#ifndef STRATEGY_H
#define STRATEGY_H

/*
 * STRATEGY DESIGN PATTERN
 * -----------------------
 * Defines a family of algorithms (draw strategies) and makes them interchangeable.
 *
 * PURPOSE:
 * - Allows the Dealer's behavior to be changed at runtime
 * - New strategies can be added without modifying existing code
 * - Follows Open/Closed Principle
 *
 * HOW IT WORKS:
 * - DrawStrategy is an abstract interface
 * - Concrete strategies implement different decision-making logic
 * - Dealer holds a pointer to DrawStrategy and delegates decisions
 *
 * BENEFITS:
 * - Easy to test with different strategies
 * - Easy to add new strategies (e.g., RandomStrategy, CountingStrategy)
 * - Decouples the "what to do" from "how to decide"
 */

// Abstract strategy interface
class DrawStrategy {
public:
    // Pure virtual function - each strategy must implement this
    virtual bool shouldDraw(int score) = 0;

    // Virtual destructor for proper cleanup through base pointer
    virtual ~DrawStrategy() = default;
};

/*
 * CONSERVATIVE STRATEGY
 * ---------------------
 * Cautious play style - stops drawing at score 15 or higher.
 * Lower risk of busting, but may lose to higher dealer scores.
 */
class ConservativeStrategy : public DrawStrategy {
public:
    bool shouldDraw(int score) override;
};

/*
 * AGGRESSIVE STRATEGY
 * -------------------
 * Risky play style - keeps drawing until score 18 or higher.
 * Higher risk of busting, but aims for higher scores.
 */
class AggressiveStrategy : public DrawStrategy {
public:
    bool shouldDraw(int score) override;
};

#endif
