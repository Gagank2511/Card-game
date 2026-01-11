#include "Strategy.h"

/*
 * STRATEGY PATTERN IMPLEMENTATIONS
 * --------------------------------
 * Each strategy encapsulates a different decision-making algorithm.
 * The Dealer uses these through polymorphism without knowing which specific strategy is used.
 */

bool ConservativeStrategy::shouldDraw(int score) {
    /*
     * Conservative approach:
     * - Stop at 15 or higher
     * - Safer, less likely to bust
     * - May result in lower final scores
     */
    return score < 15;
}

bool AggressiveStrategy::shouldDraw(int score) {
    /*
     * Aggressive approach:
     * - Keep hitting until 18 or higher
     * - Riskier, more likely to bust
     * - Aims for higher winning scores
     */
    return score < 18;
}
