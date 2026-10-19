#include <iostream>
#include <vector>

void input_vector(std::vector<int>& v)
{
    int n;
    std::cout << "Unesite broj: ";
    std::cin >> n;
    while (n != 0)
    {
        v.push_back(n);
        std::cout << "Veličina: " << v.size() << ", Kapacitet: " << v.capacity() << "\n";
        std::cout << "Unesite broj: ";
        std::cin >> n;
    }
}

void print_vector(const std::vector<int>& v)
{
    for (const auto& a : v)
    {
        std::cout << a << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> v;
    std::vector<int> drugi;
    drugi.reserve(100);
    input_vector(v);
    print_vector(v);

    for (auto it = v.rbegin(); it != v.rend(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    input_vector(drugi);
    print_vector(drugi);
    drugi.shrink_to_fit();
    std::cout << "Kapacitet drugog: " << drugi.capacity();
    return 0;
}
