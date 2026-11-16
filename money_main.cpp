// Vjezba 7, zadatak 2: napisite klasu Money i operatore iznad main.
// Datoteka racun.txt mora biti u mapi iz koje se program pokrece.

#include <fstream>
#include <iostream>
#include <string>

// ovdje napisite klasu Money i operatore
class Money
{
    int broj_centi;
public:
    Money(int euros = 0, int cents = 0) {
        broj_centi = euros * 100 + cents;
    }

    Money& operator+=(const Money& other) {
        broj_centi += other.broj_centi;
        return *this;
    }

    friend bool operator<(const Money&a, const Money& b);
    friend std::ostream& operator<<(std::ostream& os, const Money& m);
    friend std::istream& operator>>(std::istream& is, Money& m);
};

Money operator+(Money a, const Money& b) {
    a += b;
    return a;
}

bool operator<(const Money& a, const Money& b)
{
    return a.broj_centi < b.broj_centi;
}

std::ostream& operator<<(std::ostream& os, const Money& m)
{
    if (m.broj_centi % 100 < 10)
    {
        os << m.broj_centi / 100 << ".0" << m.broj_centi % 100;
    }
    else
    {
        os << m.broj_centi / 100 << "." << m.broj_centi % 100;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Money& m)
{
    int ma;
    int s = ma % 100;
    char colon;
    if (is >> ma >> colon >> s && colon == '.' && ma >= 0 && s > 0 && s < 100)
    {
        m = Money(ma, s);
    }
    else
    {
        is.setstate(std::ios::failbit);
    }
    return is;
}

int main()
{
    Money a(1, 5);
    Money b(0, 95);
    std::cout << a << " + " << b << " = " << a + b << '\n';

    std::ifstream in("racun.txt");
    if (!in) {
        std::cout << "Datoteka racun.txt ne postoji\n";
        return 1;
    }

    std::string item;
    Money price;
    Money total;
    Money max_price;
    std::string max_item;
    int count = 0;
    while (in >> item >> price) {
        total += price;
        if (max_price < price) {
            max_price = price;
            max_item = item;
        }
        ++count;
    }
    if (!in.eof())
        std::cout << "Neispravan zapis: " << item << '\n';

    std::cout << "Stavki: " << count << '\n';
    std::cout << "Ukupno: " << total << '\n';
    std::cout << "Najskuplje: " << max_item << ' ' << max_price << '\n';
    return 0;
}

/*
Ocekivani ispis:

    1.05 EUR + 0.95 EUR = 2.00 EUR
    Neispravan zapis: Sok
    Stavki: 5
    Ukupno: 17.23 EUR
    Najskuplje: Kava 7.99 EUR
*/
