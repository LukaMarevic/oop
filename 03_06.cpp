#include <iostream>
#include <string>
#include <vector>

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
    std::string rec;
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin, rec);

    std::vector<std::string> rici = split_words(rec);

    std::string najd = rici[0];
    for (const std::string& r : rici)
    {
        if (r.size() > najd.size())
        {
            najd = r;
        }
    }

    std::string obrnuto;
    for (auto i = rici.size(); i > 0; i--)
    {
        obrnuto += rici[i - 1];
        if (i > 1)
        {
            obrnuto += "-";
        }
    }

    std::string prva = rici[0];
    for (const std::string& r : rici)
    {
        if (r < prva)
        {
            prva = r;
        }
    }

    std::cout << "broj rijeci: " << rici.size() << "\n";
    std::cout << "najdulja: " << najd << "\n";
    std::cout << obrnuto << "\n";
    std::cout << "prva po abecedi: " << prva << "\n";

    return 0;
}
