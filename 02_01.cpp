#include <iostream>
#include <string>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

inline int my_max(int i, int a)
{
    return (i > a) ? i : a;
}

template<typename T>
T my_max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a = MAX(3, 5);
    int b = 2 * MAX(3, 5);
    int c = MAX(3, 5) + 1;
    std::cout << a << " " << b << " " << c << "\n";

    int i = 3;
    int d = MAX(++i, 2);
    i = 3;
    int e = my_max(++i, 2);
    std::cout << d << "\n";
    std::cout << e << "\n";

    int in = my_max(4, 5);
    double db = my_max(4.3, 5.9);
    char cc = my_max('s', 'a');
    std::string str = my_max(std::string("string1"), std::string("string2"));

    std::cout << in << " " << db << " " << cc << " " << str << "\n";
    return 0;
}
