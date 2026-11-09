// Vjezba 6, zadatak 1: napisite klasu IntStack iznad main.

#include <iostream>

// ovdje napisite klasu IntStack
class IntStack
{
    int* niz;
    int brojac;
    int velicina;
public:
    IntStack() : niz(new int[2]), brojac(0), velicina(2) {}
    ~IntStack()
    {
        delete[] niz;
    }

    IntStack(const IntStack& novi) : niz(new int[novi.velicina]), brojac(novi.brojac), velicina(novi.velicina) {
        for (int i = 0; i < velicina; i++)
        {
            niz[i] = novi.niz[i];
        }
    }

    void push(int x)
    {
        if (brojac == velicina)
        {
            int* novi = new int[velicina * 2];
            for (int i = 0; i < brojac; i++)
            {
                novi[i] = niz[i];
            }
            delete[] niz;
            niz = novi;
            velicina *= 2;
        }
        niz[brojac] = x;
        brojac += 1;
    }

    void pop()
    {
        brojac -= 1;
    }

    int top()
    {
        return niz[brojac - 1];
    }

    bool empty()
    {
        return brojac == 0;
    }

    int size()
    {
        return brojac;
    }

    int capacity()
    {
        return velicina;
    }
};

int main()
{
    IntStack s;
    for (int i = 1; i <= 5; ++i)
        s.push(i * 10);
    std::cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';
    IntStack c = s;      // copy konstruktor; isto kao IntStack c(s);
    c.pop();
    c.push(99);
    std::cout << s.top() << ' ' << c.top() << '\n';
    while (!s.empty()) { std::cout << s.top() << ' '; s.pop(); }
    std::cout << '\n';
    return 0;
}

/*
Ocekivani ispis:

    5 8 50
    50 99
    50 40 30 20 10
*/
