#include <iostream>

int& find_max(int arr[], int n)
{
    int najveci = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[najveci])
            najveci = i;
    }
    return arr[najveci];
}

int main()
{
    int numbers[] = {4, -7, 12, 0, 9, -3};
    int n = sizeof(numbers)/sizeof(numbers[0]);

    for (auto a : numbers)
    {
        std::cout << a << " ";
    }

    for (auto& x : numbers)
    {
        if (x < 0)
        {
            x = std::abs(x);
        }
    }

    std::cout << "\n";
    find_max(numbers, n) = 0;

    for (auto a : numbers)
    {
        std::cout << a << " ";
    }

    return 0;
}
