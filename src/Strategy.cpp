#include "Strategy.h"
#include <functional>  // For std::function

/*
 * STRATEGY PATTERN IMPLEMENTATIONS
 * --------------------------------
 * Each strategy encapsulates a different decision-making algorithm.
 * The Dealer uses these through polymorphism without knowing which specific strategy is used.
 *
 * FUNCTIONAL PROGRAMMING APPROACH:
 * We use lambdas to define the decision logic. This shows that the same
 * result can be achieved using functional programming techniques.
 */

bool ConservativeStrategy::shouldDraw(int score) {
    /*
     * Conservative approach:
     * - Stop at 15 or higher
     * - Safer, less likely to bust
     * - May result in lower final scores
     *
     * LAMBDA EXPLANATION:
     * Here we create a lambda that takes a score and returns true/false.
     * [threshold] captures the threshold value (15) from outside the lambda.
     */
    int threshold = 15;  // The score at which we stop drawing

    // Lambda that checks if we should draw
    auto shouldContinue = [threshold](int currentScore) {
        return currentScore < threshold;
    };

    return shouldContinue(score);  // Call the lambda with our score
}

bool AggressiveStrategy::shouldDraw(int score) {
    /*
     * Aggressive approach:
     * - Keep hitting until 18 or higher
     * - Riskier, more likely to bust
     * - Aims for higher winning scores
     */
    int threshold = 18;  // Higher threshold = more risk

    // Same lambda pattern as above
    auto shouldContinue = [threshold](int currentScore) {
        return currentScore < threshold;
    };

    return shouldContinue(score);
}
