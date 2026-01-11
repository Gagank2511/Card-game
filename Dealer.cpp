#include "Dealer.h"

Dealer::Dealer(std::unique_ptr<DrawStrategy> s)
    : strategy(std::move(s)) {}

bool Dealer::shouldDraw() {
    return strategy->shouldDraw(getScore());
}
