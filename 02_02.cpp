#include <iostream>

inline bool ascending(int a, int b)
{
    return a < b;
}

inline bool descending(int a, int b)
{
    return a > b;
}

void my_sort(int arr[], int n, bool (*cmp)(int, int))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (cmp(arr[j + 1], arr[j]))
            {
                int t = arr[j];
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

    for (int i = 0; i < n; i++)
    {
        std::cout << niz[i] << " ";
    }
    std::cout << "\n";

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

    return 0;
}
