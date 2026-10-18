#include <iostream>

inline bool ascending_prosli(int a, int b)
{
    return a < b;
}

template<typename T>
inline bool ascending(T& a, T& b)
{
    return a < b;
}

template<typename T>
inline bool descending(T& a, T& b)
{
    return a > b;
}

template<typename T>
void my_sort(T arr[], int n, bool (*cmp)(T&, T&))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (cmp(arr[j + 1], arr[j]))
            {
                T t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int main()
{
    int niz[] = {4, 1, 6, 3, 7, 2, 1, 9};
    int n = sizeof(niz)/sizeof(niz[0]);

    my_sort(niz, n, ascending);
    for (int i = 0; i < n; i++)
    {
        std::cout << niz[i] << " ";
    }
    std::cout << "\n";

    my_sort(niz, n, descending);
    for (int i = 0; i < n; i++)
    {
        std::cout << niz[i] << " ";
    }
    std::cout << "\n";

    double dupli[] = {2.4, 1.2, 6.3, 5.2, 6.2, 1.6, 6.8, 3.2};
    int nd = sizeof(dupli)/sizeof(dupli[0]);

    my_sort(dupli, nd, ascending);
    for (int i = 0; i < nd; i++)
    {
        std::cout << dupli[i] << " ";
    }
    std::cout << "\n";

    my_sort(dupli, nd, descending);
    for (int i = 0; i < nd; i++)
    {
        std::cout << dupli[i] << " ";
    }
    std::cout << "\n";

    char c[] = {'a', 'b', 'e', 'a', 'z', 'e', 'r'};
    int nc = sizeof(c)/sizeof(c[0]);

    my_sort(c, nc, ascending);
    for (int i = 0; i < nc; i++)
    {
        std::cout << c[i] << " ";
    }
    std::cout << "\n";

    my_sort(c, nc, descending);
    for (int i = 0; i < nc; i++)
    {
        std::cout << c[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
