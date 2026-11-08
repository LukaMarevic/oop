// Vjezba 5, zadatak 5: napisite klasu Ticket iznad main.

#include <iostream>
#include <string>

// ovdje napisite klasu Ticket
class Ticket
{
    std::string koncert;
    int broj;
    static int brojac;
public:
    Ticket(const std::string& konc) : koncert(konc), broj(++brojac) {}

    int get_id() const
    {
        return broj;
    }

    static int issued()
    {
        return brojac;
    }
};

int Ticket::brojac = 0;

int main()
{
    std::cout << Ticket::issued() << '\n';
    Ticket t1("Shame, Zagreb");
    Ticket t2("Shame, Zagreb");
    Ticket t3("Viagra Boys, Ljubljana");
    std::cout << t1.get_id() << ' ' << t2.get_id() << ' ' << t3.get_id() << '\n';
    std::cout << Ticket::issued() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    0
    1 2 3
    3
*/
