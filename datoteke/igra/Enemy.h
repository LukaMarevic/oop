#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

class Enemy {
    // data memberi
    int health;

public:
    // konstruktor (deklaracija; definicija je u Enemy.cpp)
    Enemy(int h);
};
