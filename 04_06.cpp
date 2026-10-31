#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

std::vector<std::string> split_words(const std::string& text)
{
    std::vector<std::string> rici;
    auto poc = text.find_first_not_of(' ');

    while (poc != std::string::npos)
    {
        auto end = text.find(' ', poc);
        if (end == std::string::npos)
        {
            rici.push_back(text.substr(poc));
            break;
        }
        rici.push_back(text.substr(poc, end - poc));
        poc = text.find_first_not_of(' ', end);
    }
    return rici;
}

int main()
{
    std::vector<std::string> rjecnik = {"programski", "jezik", "c++", "je", "brz", "i", "mocan", "ali", "nije", "jednostavan", "za", "pocetnike"};

    std::sort(rjecnik.begin(), rjecnik.end());

    std::string recenica;
    std::cout << "Recenica: ";
    std::getline(std::cin, recenica);

    std::vector<std::string> nepoznate;
    for (std::string r : split_words(recenica))
    {
        r.erase(std::remove_if(r.begin(), r.end(),
                    [](char c) { return c == ',' || c == '.'; }),
                r.end());

        std::transform(r.begin(), r.end(), r.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        if (!std::binary_search(rjecnik.begin(), rjecnik.end(), r))
        {
            nepoznate.push_back(r);
        }
    }

    std::cout << "nepoznatih rijeci: " << nepoznate.size() << " ";
    for (const auto& r : nepoznate)
    {
        std::cout << r << " ";
    }

    return 0;
}
