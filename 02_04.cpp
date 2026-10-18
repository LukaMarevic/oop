#include <iostream>

void my_transform(int arr[], int n, int (*f)(int))
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = f(arr[i]);
    }
}

int twice(int x)
{
    return 2 * x;
}

int main()
{
    int niz[] = {6, 2, 7, 1, 4};
    int n = sizeof(niz) / sizeof(niz[0]);

    my_transform(niz, n, twice);
    for (int i = 0; i < n; i++)
    {
        std::cout << niz[i] << " ";
    }
    std::cout << "\n";

    int niz2[] = {7, 3, 1, 6, 2, 6};
    int n2 = sizeof(niz2) / sizeof(niz2[0]);
    my_transform(niz2, n2, [](int x) { return x % 2 == 0 ? x / 2 : x * 2; });
    for (int i = 0; i < n2; i++)
    {
        std::cout << niz2[i] << " ";
    }
    std::cout << "\n";

    int niz3[] = {2, 4, 1, 6, 2, 6};
    int n3 = sizeof(niz3) / sizeof(niz3[0]);

    int suma = 0;
    int prod = 1;
    auto sumaaa = [&](int x)
    {
        suma += x;
        prod *= x;
    };
    for (int i = 0; i < n3; i++)
    {
        sumaaa(niz3[i]);
    }
    std::cout << suma << " " << prod << "\n";

    int prag = 3;
    int s = 0;
    auto sumaveca = [prag, &s](int x) { if (x > prag) s += x; };
    for (int i = 0; i < n3; i++)
    {
        sumaveca(niz3[i]);
    }
    std::cout << s << "\n";

    return 0;
}
