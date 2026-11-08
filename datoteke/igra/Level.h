#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <vector>
#include "Enemy.h"
#include "Weapon.h"

class Level {
    // data memberi
    std::vector<Enemy> protivnik;
    std::vector<Weapon> oruzje;

public:
    // konstruktor
    Level(const Enemy& protivnik);
    int enemy_count() const;
    int weapon_count() const;
};
