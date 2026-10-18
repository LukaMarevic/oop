#include <iostream>
#include <string>

struct Student
{
    std::string ime;
    int jmbag;
    int godina;
    int ects;
    double prosjek;
};

void ispisi(Student& s)
{
    std::cout << s.ime << " " << s.jmbag << " " << s.godina<< " " << s.ects << " " << s.prosjek << "\n";
}

void povecaj_godinu(Student& s)
{
    s.godina++;
}

void filter_students(Student s[], int n, void (*action)(Student&), bool (*cond)(const Student&))
{
    for (int i = 0; i < n; i++)
        if (cond(s[i]))
            action(s[i]);
}

int main()
{
    Student s[] = {
        {"Luka Marevic", 532626251, 2, 60, 3.19},
        {"Marin Maric", 35125211, 2, 53, 4.2},
        {"Petar Peric", 21521531, 4, 43, 2.5},
        {"Ivo Ivic", 1521563, 1, 21, 3.20}
    };
    int n = sizeof(s)/sizeof(s[0]);

    std::cout << "Bar jedan položen ispit:\n";
    filter_students(s, n, ispisi,[](const Student& s) { return s.godina == 1 && s.ects > 0; });

    std::cout << "\nProsjek veci od 3.5:\n";
    filter_students(s, n, ispisi,[](const Student& s) { return s.prosjek > 3.5; });

    filter_students(s, n, povecaj_godinu,[](const Student& s) { return s.ects >= 45; });

    std::cout << "\nPovećana godina:\n";
    filter_students(s, n, ispisi,[](const Student&) { return true; });
    return 0;
}
