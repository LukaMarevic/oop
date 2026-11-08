#include <iostream>
#include "Game.h"

// definicije konstruktora i metode print
Game::Game(const std::string& title, const std::string& player_name) : title(title), lvl(Enemy(100)), player_name(player_name, &lvl){}

void Game::print() const
{
    std::cout << title << "\n";
    player_name.print();
}
