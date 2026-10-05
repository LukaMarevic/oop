#include <iostream>

int main()
{
    int a{};
    int b{};
    int zbroj{};
    double arit{};
    std::cout << "Unesi 2 broja: \n";
    std::cin >> a;
    std::cin >> b;
    zbroj = a + b;
    std::cout << "Zbroj: " << zbroj << "\n";
    arit = zbroj / 2.0;
    std::cout << "Aritmetička sredina: " << arit << "\n";
    bool bo = a < b;
    std::cout << "a < b " << bo;
    return 0;
}
