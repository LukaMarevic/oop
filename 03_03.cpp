#include <iostream>
#include <array>

constexpr int DAYS = 7;

double total(const std::array<double, DAYS>& hours)
{
    double zbr = 0;
    for (double d : hours)
    {
        zbr += d;
    }
    return zbr;
}

int best_day(const std::array<double, DAYS>& hours)
{
    int najv = 0;
    for (int i = 1; i < DAYS; i++)
    {
        if (hours[i] > hours[najv])
        {
            najv = i;
        }
    }
    return najv + 1;
}

int main()
{
    std::array<double, DAYS> prvi{};

    for (int i = 0; i < DAYS; i++)
    {
        std::cout << "Unesite sate: ";
        std::cin >> prvi[i];
    }

    std::cout << "\nUkupni sati za prvi tjedan: " << total(prvi);
    std::cout << "\nDan s najviše sati prvi tjedan: " << best_day(prvi);

    std::array<double, DAYS> drugi{};
    drugi.fill(1.5);
    std::cout << "\n" << (prvi == drugi) << " " << (drugi < prvi);
    prvi.swap(drugi);

    std::cout << "\nUkupni sati za prvi tjedan: " << total(prvi);
    std::cout << "\nUkupni sati za drugi tjedan: " << total(drugi);

    return 0;
}
