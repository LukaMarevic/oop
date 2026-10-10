#include <iostream>

namespace geo
{
    const double PI = 3.14;
}

double area(double r)
{
    return r*r*(geo::PI);
}

double area(double a, double b)
{
    return a*b;
}

int area(int a)
{
    return a*a;
}

void print_line(char c = '-', int length = 30)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << c;
    }
    std::cout << "\n";
}

int main()
{
    print_line();
    std::cout << "Krug " << area(5.0) << "\n";

    print_line();
    std::cout << "Kvadrat " << area(5) << "\n";

    print_line();
    std::cout << "Pravokutnik " << area(2, 3) << "\n";

    print_line();
    std::cout << "A " << area('A') << "\n";

    print_line();
}
