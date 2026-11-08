// Vjezba 5, zadatak 3: napisite strukturu Song i klasu Album iznad main.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite Song i Album
class Song {
public:
    std::string title;
    std::string artist;
    int seconds;
    Song(const std::string& t, const std::string& a, int s)
        : title(t), artist(a), seconds(s){}
};

class Album {
    std::string title;
    int year;
    std::vector<Song> songs;
public:
    Album(const std::string& t, int y, const Song& first)
        : title(t), year(y), songs{first}{}

    bool add(const Song& s)
    {
        for (const auto& sq : songs)
        {
            if (sq.title == s.title)
            {
                return false;
            }
        }
        songs.push_back(s);
        return true;
    }

    int duration() const {
        int sek = 0;
        for (const auto& s : songs)
        {
            sek += s.seconds;
        }
        return sek;
    }

    void print() const {
        int d = duration();
        int sek = d % 60;
        std::cout << title << " (" << year << "), " << songs.size() << " pjesme, " << d / 60 << ':';
        if (sek < 10)
        {
            std::cout << "0";
        }
        std::cout << sek << "\n";
        for (int i = 0; i < songs.size(); ++i)
        {
            std::cout << "  " << i + 1 << ". " << songs[i].title << "\n";
        }
    }
};

int main()
{
    Album a("Sol Invictus", 2015, {"Sol Invictus", "Faith No More", 156});
    a.add({"Superhero", "Faith No More", 315});
    a.add({"Matador", "Faith No More", 368});
    std::cout << a.add({"Superhero", "Faith No More", 315}) << '\n';   // vec postoji
    a.print();
    return 0;
}

/*
Ocekivani ispis:

    0
    Sol Invictus (2015), 3 pjesme, 13:59
      1. Sol Invictus
      2. Superhero
      3. Matador
*/
