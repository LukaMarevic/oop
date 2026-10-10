#include <iostream>

struct Fraction
{
    int numerator;
    int denominator;

    void reduce() {
        int i;
        if (numerator > denominator)
            i = denominator;
        else
            i = numerator;

        while (i > 1)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                numerator /= i;
                denominator /= i;
                break;
            }
            i--;
        }

    }
    double value() {return static_cast<double>(numerator) / denominator;}
    void print() {std::cout << numerator << "/" << denominator;}
};

Fraction sum(const Fraction& a, const Fraction& b)
{
    Fraction nova;
    nova.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    nova.denominator = a.denominator * b.denominator;
    nova.reduce();
    return nova;
}

int main()
{
    Fraction prva{4, 2};
    Fraction druga{12, 18};
    Fraction treca{3, 4};

    prva.print();
    std::cout << "\n";

    double rez = prva.value();
    std::cout << "Vrijednost: " << rez << "\n";

    druga.reduce();
    std::cout << druga.numerator << ", " << druga.denominator << "\n";

    Fraction novaa = sum(prva, treca);
    std::cout << "Skraćeni zbroj prve i treće: ";
    novaa.print();

    return 0;
}
