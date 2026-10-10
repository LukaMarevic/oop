#include <iostream>
#include <string>
#include <limit>

int main()
{
    int godina{};
    std::string str{};
    std::cout << "Unesite godinu rođenja: \n";
    std::cin >> godina;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Unesite ime i prezime: \n";
    std::getline(std::cin, str);

    std::string inic{};
    bool pocetak = true;
    for (char c : str)
    {
        if (c == ' ')
            pocetak = true;
        else if (pocetak)
        {
            inic = inic + c + ".";
            pocetak = false;
        }
    }
    std::cout << "Inicijali: " << inic << "\n";

    int broj{};
    for (char c : str)
    {
        if (c != ' ')
            broj++;
    }
    std::cout << "Broj znakova imena i prezimena: " << broj << "\n";

    int god = 2026 - godina;
    std::cout << "Broj godina osobe: " << god << "\n";
    return 0;
}
