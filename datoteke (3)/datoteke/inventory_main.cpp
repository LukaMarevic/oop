// Vjezba 7, zadatak 4: napisite klasu Inventory iznad funkcije show.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite klasu Inventory
class Inventory
{
    int maks;
    std::vector<std::string> items;

public:
    Inventory(int maks) : maks(maks) {}

    Inventory& operator+=(const std::string& item)
    {
        if (size() < maks)
        {
            items.push_back(item);
        }
        return *this;
    }

    std::string& operator[](int i)
    {
        return items[i];
    }

    const std::string& operator[](int i) const
    {
        return items[i];
    }

    int size() const
    {
        return items.size();
    }

    explicit operator bool() const
    {
        return !items.empty();
    }
};

void show(const Inventory& inv)
{
    if (!inv) {
        std::cout << "prazno\n";
        return;
    }
    for (std::size_t i = 0; i < inv.size(); ++i)
        std::cout << i << ": " << inv[i] << '\n';
}

int main()
{
    Inventory bag(3);
    show(bag);

    bag += "mac";
    bag += "stit";
    bag += "kljuc";
    bag += "baklja";          // ne stane
    show(bag);

    bag[0] = "zlatni mac";
    std::cout << bag[0] << ' ' << bag.size() << '\n';

    if (bag)
        std::cout << "ima predmeta\n";
    return 0;
}

/*
Ocekivani ispis:

    prazno
    0: mac
    1: stit
    2: kljuc
    zlatni mac 3
    ima predmeta
*/
