#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cout << "Unesite broj temperatura: ";
    std::cin >> n;

    std::vector<double> temper(n);

    for (int i = 0; i < n; i++)
    {
        std::cout << "Unesite temperaturu: ";
        std::cin >> temper[i];
    }

    std::vector<double> prom;
    prom.reserve(n-1);

    for (auto it = temper.begin(); it + 1 != temper.end(); it++)
    {
        prom.push_back(*(it + 1) - *it);
    }

    std::cout << "Promjene: ";
    for (double p : prom)
        std::cout << p << " ";
    std::cout << "\n";

    if (n != 7)
    {
        temper.resize(7, temper.back());
    }

    std::cout << "Izvjestaj: ";
    for (double t : temper)
        std::cout << t << " ";
    std::cout << "\n";

    std::vector<int> a(5);
    std::vector<int> b{5};
    std::cout << "a: " << a.size() << "\n";
    std::cout << "b: " << b.size();

    return 0;
}
