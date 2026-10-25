#include <iostream>
#include <string>

 std::string with_separators(std::string digits)
 {
    auto poc = 0;

    if (digits[0] == '-')
    {
        poc = 1;
    }

    for (auto poz = digits.size(); poz > poc + 3;)
    {
        poz -= 3;
        digits.insert(poz, ".");
    }
    return digits;
 }

 std::string without_separators(std::string text)
 {
    auto poz = text.find('.');
    while (poz != std::string::npos)
    {
        text.erase(poz, 1);
        poz = text.find('.');
    }
    return text;
 }

int main()
{
    std::string s = "1234567";
    std::string ms = "-221234567";
    std::string sto = "100000";
    std::string stot = "1.234.567";
    std::cout << s << "->" << with_separators(s) << "\n";
    std::cout << ms << "->" << with_separators(ms) << "\n";
    std::cout << sto << "->" << with_separators(sto) << "\n";
    std::cout << stot << "->" << without_separators(stot) << "\n";
    return 0;
}
