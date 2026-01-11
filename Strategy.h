#ifndef STRATEGY_H
#define STRATEGY_H

class DrawStrategy {
public:
    virtual bool shouldDraw(int score) = 0;
    virtual ~DrawStrategy() = default;
};

class ConservativeStrategy : public DrawStrategy {
public:
    bool shouldDraw(int score) override;
};

class AggressiveStrategy : public DrawStrategy {
public:
    bool shouldDraw(int score) override;
};

#endif
