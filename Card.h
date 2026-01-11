#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card {
protected:
    int value;
    string name;

public:
    Card(int v, string n);
    virtual int getValue() const = 0;
    virtual string getName() const = 0;
    virtual ~Card();
};

class NormalCard : public Card {
public:
    NormalCard(int v, string n);
    int getValue() const override;
    string getName() const override;
};

class FaceCard : public Card {
public:
    FaceCard(string n);
    int getValue() const override;
    string getName() const override;
};

#endif
