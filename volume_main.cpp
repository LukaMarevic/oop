// Vjezba 5, zadatak 1: napisite klasu Volume iznad main.

#include <cassert>
#include <iostream>

// ovdje napisite klasu Volume
class Volume {
    int glasnoca;
    int prije;

    static int ogr(int l)
    {
        if (l < 0)
            l = 0;
        else if (l > 100)
            l = 100;
        return l;
    }
public:
    Volume(int l)
    {
        glasnoca = ogr(l);
        prije = 0;
        assert(valid());
    }
    Volume() : Volume(50) {}

    int get() {
        return glasnoca;
    }

    void up(int step = 10) {
        glasnoca = ogr(glasnoca + step);
        assert(valid());
    }

    void down(int step = 10) {
        glasnoca = ogr(glasnoca - step);
        assert(valid());
    }

    void mute() {
        prije = glasnoca;
        glasnoca = 0;
        assert(valid());
    }

    void unmute() {
        glasnoca = prije;
        assert(valid());
    }
private:
    bool valid() const {return glasnoca >= 0 && glasnoca < 101;}
};

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
