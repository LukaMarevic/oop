#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <string>

struct PasswordInfo
{
    int length;
    int digits;
    int uppercase;
    int special;
};

PasswordInfo analyze(const std::string& password)
{
    PasswordInfo loz;
    loz.length = password.size();
    loz.digits = std::count_if(password.begin(), password.end(),
        [](char c) { return std::isdigit(c); });
    loz.uppercase = std::count_if(password.begin(), password.end(),
        [](char c) { return std::isupper(c); });
    loz.special = std::count_if(password.begin(), password.end(),
        [](char c) { return std::ispunct(c); });
    return loz;
}

bool is_strong(const PasswordInfo& info)
{
    return info.length >= 10 && info.digits >= 1 && info.uppercase >= 1 && info.special >= 1;
}

int main()
{
    std::vector<std::string> lozinke = {"lozinka123", "Lozinka123!"};
    for (const auto& p : lozinke)
    {
        PasswordInfo loz = analyze(p);
        std::cout << p << ": duljina " << loz.length << ", znamenke " << loz.digits
                  << ", velika " << loz.uppercase << ", posebni " << loz.special
                  << " -> ";
        if (is_strong(loz))
        {
            std::cout << "jaka\n";
        }
        else
        {
            std::cout << "slaba\n";
        }
    }
    return 0;
}
