#include "Game.h"
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(nullptr));

    Game game;
    game.play();

    return 0;
}
