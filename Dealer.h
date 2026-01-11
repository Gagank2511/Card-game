#ifndef DEALER_H
#define DEALER_H

#include "Player.h"
#include "Strategy.h"
#include <memory>

class Dealer : public Player {
private:
    std::unique_ptr<DrawStrategy> strategy;

public:
    Dealer(std::unique_ptr<DrawStrategy> s);
    bool shouldDraw();
};

#endif
