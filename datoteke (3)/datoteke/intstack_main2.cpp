// Vjezba 7, zadatak 3: kopirajte klasu IntStack iz vjezbe 6 iznad main i dopunite je.

#include <iostream>
#include <utility>

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

    IntStack(const IntStack& o) : niz(new int[o.velicina]), brojac(o.brojac), velicina(o.velicina)
    {
        std::cout << "copy konstruktor\n";
        for (int i = 0; i < brojac; i++)
        {
            niz[i] = o.niz[i];
        }
    }

    IntStack& operator=(const IntStack& i)
    {
        std::cout << "copy assignment\n";
        if (this != &i)
        {
            int* novi = new int[i.velicina];
            for (int j = 0; j < i.brojac; j++)
            {
                novi[j] = i.niz[j];
            }
            delete[] niz;
            niz = novi;
            brojac = i.brojac;
            velicina = i.velicina;
        }
        return *this;
    }

    IntStack(IntStack&& i) noexcept : niz(i.niz), brojac(i.brojac), velicina(i.velicina)
    {
        std::cout << "move konstruktor\n";
        i.niz = nullptr;
        i.brojac = 0;
        i.velicina = 0;
    }

    IntStack& operator=(IntStack&& i) noexcept
    {
        std::cout << "move assignment\n";
        if (this != &i)
        {
            delete[] niz;
            niz = i.niz;
            brojac = i.brojac;
            velicina = i.velicina;
            i.niz = nullptr;
            i.brojac = 0;
            i.velicina = 0;
        }
        return *this;
    }

    void push(int x)
    {
        int nova = velicina * 2;
        if (velicina == 0)
        {
            nova = 2;
        }
        if (brojac == velicina)
        {
            int* novi = new int[nova];
            for (int i = 0; i < brojac; i++)
            {
                novi[i] = niz[i];
            }
            delete[] niz;
            niz = novi;
            velicina =nova;
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
    IntStack a;
    a.push(10);
    a.push(20);
    a.push(30);

    IntStack b = a;              // ispis: copy konstruktor
    b = a;                       // ispis: copy assignment
    IntStack c = std::move(a);   // ispis: move konstruktor
    b = std::move(c);            // ispis: move assignment

    std::cout << a.size() << ' ' << c.size() << ' ' << b.size() << ' ' << b.top() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    copy konstruktor
    copy assignment
    move konstruktor
    move assignment
    0 0 3 30
*/
