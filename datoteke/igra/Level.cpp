#include "Level.h"

// definicije konstruktora i metoda
Level::Level(const Enemy& protivnik) : protivnik{protivnik} {}
int Level::enemy_count() const
{
    return protivnik.size();
}

int Level::weapon_count() const
{
    return oruzje.size();
}
