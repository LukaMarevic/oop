// Vjezba 8, zadatak 2: napisite klase Enemy, Goblin, Bat, Ghost i Level iznad main.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite klase
class Enemy
{
protected:
    std::string ime;
    int zdravlje;
public:
    Enemy(const std::string& n, int m) : ime(n), zdravlje(m) {}
    virtual ~Enemy() {
        std::cout << ime << " nestaje\n";
    }

    virtual void take_damage(int d)
    {
        zdravlje -= d;

        if (zdravlje < 0)
        {
            zdravlje = 0;
        }
    }

    int get_health() const {
        return zdravlje;
    }

    std::string get_name() const {
        return ime;
    }
};

class Goblin : public Enemy {
public:
    Goblin() : Enemy("Goblin", 20) {}
};

class Bat : public Enemy
{
    int i = 0;
public:
    Bat() : Enemy("Bat", 15) {}

    void take_damage(int d) override {
        if (i % 2 == 0)
        {
            zdravlje -= d;
        }
        else
        {
            std::cout << "Bat izbjegne udarac\n";
        }
        i++;

        if (zdravlje < 0)
        {
            zdravlje = 0;
        }
    }
};

class Ghost : public Enemy
{
public:
    Ghost() : Enemy("Ghost", 30) {}

    void take_damage(int d) override {
        zdravlje -= d / 2;

        if (zdravlje < 0)
        {
            zdravlje = 0;
        }
    }
};

class Level
{
    std::vector<Enemy*> neprijatelji;
public:
    Level() {}
    ~Level() {
        for (Enemy* e : neprijatelji)
        {
            delete e;
        }
    }

    Level(const Level&) = delete;
    Level& operator=(const Level&) = delete;

    void add(Enemy* e)
    {
        neprijatelji.push_back(e);
    }

    int size()
    {
        return neprijatelji.size();
    }

    void remove_dead()
    {
        for (int i = 0; i < neprijatelji.size();)
        {
            if (neprijatelji[i]->get_health() <= 0)
            {
                delete neprijatelji[i];
                neprijatelji.erase(neprijatelji.begin() + i);
            }
            else
            {
                i++;
            }
        }
    }

    void explode(int d)
    {
        for (int i = 0; i < neprijatelji.size(); i++) {
            neprijatelji[i]->take_damage(d);
        }
    }

    void print() const
    {
        for (Enemy* e : neprijatelji)
        {
            std::cout << e->get_name() << " " << e->get_health() << "\n";
        }
    }

};


int main()
{
    Level cave;
    cave.add(new Goblin);            // od sada je cave vlasnik neprijatelja
    cave.add(new Bat);
    cave.add(new Ghost);
    cave.add(new Goblin);
    std::cout << cave.size() << '\n';

    cave.explode(10);                // bomba pogodi sve neprijatelje
    cave.print();
    std::cout << "---\n";
    cave.explode(10);
    cave.print();
    std::cout << "---\n";
    cave.remove_dead();
    std::cout << cave.size() << '\n';
    std::cout << "--- kraj ---\n";
    return 0;                        // destruktor klase Level brise preostale neprijatelje
}

/*
Ocekivani ispis:

    4
    Goblin 10
    Bat 5
    Ghost 25
    Goblin 10
    ---
    Bat izbjegne udarac
    Goblin 0
    Bat 5
    Ghost 20
    Goblin 0
    ---
    Goblin nestaje
    Goblin nestaje
    2
    --- kraj ---
    Bat nestaje
    Ghost nestaje
*/
