#include <iostream>
#include "Player.h"

// definicije konstruktora i metode print
Player::Player(const std::string& ime, Level* lvl) : ime(ime), lvl(lvl) {}

void Player::print() const
{
    std::cout << "Igrac: " << ime;
    std::cout << "\nLevel: neprijatelja: " << lvl->enemy_count()
              << ", oruzja " << lvl->weapon_count() << "\n";
}
