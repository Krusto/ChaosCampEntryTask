#include "BattleshipGame.hpp"

int main()
{
    BattleshipGame game;
    game.Init(10, 10, 6, 3);
    while (!game.ShouldExit()) { game.Run(); }

    return 0;
}