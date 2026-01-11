#include "Card.h"

// Base
Card::Card(int v, string n) : value(v), name(n) {}
Card::~Card() {}

// Normal Card
NormalCard::NormalCard(int v, string n) : Card(v, n) {}
int NormalCard::getValue() const { return value; }
string NormalCard::getName() const { return name; }

// Face Card
FaceCard::FaceCard(string n) : Card(10, n) {}
int FaceCard::getValue() const { return 10; }
string FaceCard::getName() const { return name; }
