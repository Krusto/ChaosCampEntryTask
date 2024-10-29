#include "BattleshipGame.hpp"

int main()
{
    BattleshipGame game;
    game.Init(5, 5, 3, 3);
    while (!game.Run()) {}

    return 0;
}