// Vjezba 5, zadatak 1: napisite klasu Volume iznad main.

#include <cassert>
#include <iostream>

// ovdje napisite klasu Volume

int main()
{
    Volume v;
    std::cout << v.get() << '\n';
    v.up();
    v.up(60);
    std::cout << v.get() << '\n';
    v.mute();
    std::cout << v.get() << '\n';
    v.unmute();
    std::cout << v.get() << '\n';
    Volume w(-20);
    w.down();
    std::cout << w.get() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    50
    100
    0
    100
    0
*/
