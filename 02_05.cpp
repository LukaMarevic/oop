#include <iostream>

inline double add(double a, double b){return a + b;}
inline double subtract(double a, double b){return a - b;}
inline double multiply(double a, double b){return a * b;}
inline double divide(double a, double b){return a / b;}

int main()
{
    double (*operacije[4])(double, double) = { add, subtract, multiply, divide };
    double x;
    double y;
    int oper;

    std::cout << "Unesite broj ";
    std::cin >> x;
    std::cout << "Unesite broj ";
    std::cin >> y;
    std::cout << "Unesi broj operacije ";
    std::cin >> oper;

    if (oper < 0 || oper > 3)
    {
        std::cout << "Krivi broj\n";
    }
    else if (oper == 3 && y == 0)
    {
        std::cout << "Ne moe se dijeliti s nulom\n";
    }
    else
    {
        std::cout << operacije[oper](x, y) << "\n";
    }
    return 0;
}
