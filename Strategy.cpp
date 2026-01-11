#include "Strategy.h"

bool ConservativeStrategy::shouldDraw(int score) {
    return score < 15;
}

bool AggressiveStrategy::shouldDraw(int score) {
    return score < 18;
}
