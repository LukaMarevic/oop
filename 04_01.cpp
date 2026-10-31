#include <iostream>
#include <vector>
#include <algorithm>

void input_vector(std::vector<int>& v)
{
    int n;
    while (std::cin >> n && n != 0)
    {
        v.push_back(n);
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
    std::cout << "Unesite brojeve (0 za kraj): ";
    input_vector(v);

    int k;
    std::cout << "Unesite broj: ";
    std::cin >> k;
    if (k <= 0) {
        std::cout << "k mora biti veci od 0\n";
        return 0;
    }

    auto neg = std::count_if(v.begin(), v.end(), [](int x) { return x < 0; });
    std::cout << "negativnih: " << neg << "\n";

    auto it = std::find_if(v.begin(), v.end(), [k](int x) { return x % k == 0; });
    if (it == v.end())
    {
        std::cout << "Nema visekratnika\n";
    }
    else
    {
        std::cout << "prvi visekratnik od  " << k << ": " << *it << "(pozicija " << std::distance(v.begin(), it) << ")\n";
    }

    auto mini = std::min_element(v.begin(), v.end());
    auto maxi = std::max_element(v.begin(), v.end());
    std::cout << "min " << *mini << " (pozicija " << std::distance(v.begin(), mini) << "), "
              << "max " << *maxi << " (pozicija " << std::distance(v.begin(), maxi) << ")\n";

    v.erase(std::remove_if(v.begin(), v.end(), [k](int x) {return x % k == 0;}), v.end());
    std::cout << "bez visekratnika: ";
    print_vector(v);

    return 0;
}
