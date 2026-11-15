// Vjezba 6, zadatak 3: napisite klasu LogFile i funkciju log_songs iznad main.

#define _CRT_SECURE_NO_WARNINGS    // za Visual Studio: dopusta std::fopen
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

// ovdje napisite klasu LogFile i funkciju log_songs
class LogFile
{
    std::FILE* f;

public:
    LogFile(const std::string& name) : f(std::fopen(name.c_str(), "a")) {}
    ~LogFile()
    {
        std::fclose(f);
    }

    LogFile(const LogFile&) = delete;

    void write(const std::string& line)
    {
        std::fputs(line.c_str(), f);
        std::fputs("\n", f);
    }
};

int log_songs(const std::vector<std::string>& titles)
{
    LogFile log("played.log");
    int brojac = 0;
    for (const auto& t : titles)
    {
        if (t == "STOP")
        {
            return brojac;
        }
        log.write(t);
        brojac++;
    }
    return brojac;
}

int main()
{
    std::remove("played.log");     // brise datoteku iz prethodnog pokretanja
    int n = log_songs({"Superhero", "Sports", "STOP", "Matador"});
    std::cout << n << '\n';
    std::cout << log_songs({"One Rizla"}) << '\n';

    // ispis sadrzaja datoteke
    std::FILE* f = std::fopen("played.log", "r");
    char line[100];
    while (std::fgets(line, sizeof line, f))
        std::cout << line;
    std::fclose(f);
    return 0;
}

/*
Ocekivani ispis:

    2
    1
    Superhero
    Sports
    One Rizla
*/
