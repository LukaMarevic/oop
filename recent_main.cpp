// Vjezba 6, zadatak 6: napisite klasu RecentlyPlayed iznad main.

#include <cassert>
#include <iostream>
#include <string>

// ovdje napisite klasu RecentlyPlayed
class RecentlyPlayed
{
    std::string* niz;
    int kapacitet;
    int broj;
    int iduci;
public:
    RecentlyPlayed(int kap) : niz(new std::string[kap]), kapacitet(kap), broj(0), iduci(0)
    {
        assert(kapacitet > 0);
    }
    ~RecentlyPlayed()
    {
        delete[] niz;
    }

    RecentlyPlayed(const RecentlyPlayed& other) : niz(new std::string[other.kapacitet]), kapacitet(other.kapacitet), broj(other.broj), iduci(other.iduci)
    {
        for (int i = 0; i < kapacitet; i++)
        {
            niz[i] = other.niz[i];
        }
    }

    void play(const std::string& title)
    {
        niz[iduci] = title;
        iduci = (iduci + 1) % kapacitet;
        if (broj < kapacitet)
        {
            broj++;
        }
    }

    int size() const { return broj; }
    int capacity() const { return kapacitet; }

    const std::string& get(int i) const
    {
        assert(i >= 0 && i < broj);
        return niz[(iduci - 1 - i + kapacitet) % kapacitet];
    }

    void print() const
    {
        for (int i = 0; i < broj; i++)
        {
            if (i > 0)
            {
                std::cout << ", ";
            }
            std::cout << get(i);
        }
        std::cout << "\n";
    }
};

int main()
{
    RecentlyPlayed recent(3);
    recent.play("Heroes");
    recent.play("Literary Mind");
    std::cout << recent.size() << ' ' << recent.capacity() << '\n';
    recent.play("Sports");
    recent.print();
    recent.play("Henry Don't Got Love");     // buffer je pun: prepisuje se najstarija
    recent.print();

    RecentlyPlayed copy = recent;             // copy konstruktor
    recent.play("Guided by Angels");
    recent.print();
    copy.print();
    std::cout << copy.get(0) << '\n';
    return 0;
}

/*
Ocekivani ispis:

    2 3
    Sports, Literary Mind, Heroes
    Henry Don't Got Love, Sports, Literary Mind
    Guided by Angels, Henry Don't Got Love, Sports
    Henry Don't Got Love, Sports, Literary Mind
    Henry Don't Got Love
*/
