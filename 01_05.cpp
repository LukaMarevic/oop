#include <iostream>
#include <cmath>

struct Point
{
    double x;
    double y;
};

void move_by(Point* p, double dx, double dy)
{
    p->x += dx;
    p->y += dy;
}

double dist(const Point* a, const Point* b)
{
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    return std::sqrt(dx * dx + dy * dy);
}

void move_by(Point& p, double dx, double dy)
{
    p.x += dx;
    p.y += dy;
}

double dist(const Point& a, const Point& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

int main()
{
    Point prvi = {2.0, 5.0};
    Point drugi = {3.0, 2.5};

    move_by(&prvi, 2.0, 2.0);
    move_by(&drugi, 2.0, 2.0);
    std::cout << "Pointeri: a: " << prvi.x << ", " << prvi.y << ", " << "dist: " << dist(&prvi, &drugi) << "\n";
    std::cout << "Pointeri: b: " << drugi.x << ", " << drugi.y << ", " << "dist: " << dist(prvi, drugi) << "\n";

    move_by(prvi, 1.0, 1.0);
    move_by(drugi, 1.0, -1.0);
    std::cout << "Reference: a: " << prvi.x << ", " << prvi.y << ", " << "dist: " << dist(&prvi, &drugi) << "\n";
    std::cout << "Reference: b: " << drugi.x << ", " << drugi.y << ", " << "dist: " << dist(prvi, drugi) << "\n";


    Point niz[5] = {
        {1.0, 4.0},
        {5.4, 1.1},
        {4.0, 4.6},
        {7.0, 3.1},
        {2.4, 1.2}
    };
    Point ishodiste{0.0, 0.0};

    Point* najblizi = &niz[0];
    double najb = dist(*najblizi, ishodiste);
    for (Point& p : niz)
    {
        double duz = dist(p, ishodiste);
        if (duz < najb)
        {
            najb = duz;
            najblizi = &p;
        }
    }

    std::cout << "Najbliži ishodištu: " << najblizi->x << ", " << najblizi->y << "\n";
    return 0;
}
