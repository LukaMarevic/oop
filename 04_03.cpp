#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool starts_with(const std::string& s, const std::string& prefix)
{
    return std::equal(prefix.begin(), prefix.end(), s.begin());
}

bool ends_with(const std::string& s, const std::string& suffix)
{
    return std::equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main()
{
    std::vector<std::string> datoteka =  {"vjezba04.cpp", "slajdovi.pdf", "main.cpp", " README.md", "vjezba04.h", "notes.txt", "vjezba03.cpp"};

    auto cpp = std::count_if(datoteka.begin(), datoteka.end(),
                             [](const std::string& f) { return ends_with(f, ".cpp"); });
    std::cout << ".cpp datoteka: " << cpp << "\n";

    datoteka.erase(std::remove_if(datoteka.begin(), datoteka.end(),
                               [](const std::string& f) { return starts_with(f, "vjezba"); }),datoteka.end());

    for (const auto& d : datoteka)
    {
        std::cout << d << " ";
    }
    return 0;
}
