#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Song
{
    std::string title;
    std::string artist;
    int year;
    int plays;
};

void print_song(const Song& s)
{
    std::cout << s.title << " " << s.artist << " " << s.year << " " << s.plays << "\n";
}

int main()
{
    std::vector<Song> pisme{
      {"Pisma1", "Marevic", 2004, 205382},
      {"Pisma", "Mara", 2016, 53262},
      {"Objektno", "Marevic", 2016, 512154},
      {"OOP", "Kopilica", 2013, 5412},
      {"Pisma3", "Kopilica", 1999, 69341},
    };

    for (const auto& p : pisme)
    {
        print_song(p);
    }
    std::cout << "\n";

    sort(pisme.begin(), pisme.end(),
              [](const Song& a, const Song& b) {if (a.year == b.year) {return a.title < b.title;} return a.year < b.year;});

    for (const auto& p : pisme)
    {
        print_song(p);
    }

    std::cout << "\n";

    std::string ime;
    std::cout << "Unesite ime ivodaca: ";
    std::getline(std::cin, ime);

    auto piva = [&ime] (const Song& s)
    {
        return s.artist == ime;
    };

    int brojac = std::count_if(pisme.begin(), pisme.end(), piva);

    if (brojac > 0)
    {
        auto najs = std::find_if(pisme.begin(), pisme.end(), piva);
        std::cout << "Izvodac ima " << brojac << " pjesme, najstarija je: ";
        print_song(*najs);
    }
    else
    {
        std::cout << "Nema pjesama ovog izvodaca\n";
    }
    std::cout << "\n";

    auto it = std::max_element(pisme.begin(), pisme.end(),
                    [](const Song& s1, const Song& s2) {
                            return s2.plays > s1.plays;
                    });

    std::cout << "Najslusanija pjesma: ";
    print_song(*it);

    return 0;
}
