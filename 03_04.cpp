#include <iostream>
#include <string>

bool split_email(const std::string& email, std::string& user, std::string& domain)
{
    auto et1 = email.find("@");

    if (et1 != email.rfind("@") || et1 == std::string::npos || et1 == 0 || et1 == email.size()-1)
    {
        return false;
    }

    std::string dom = email.substr(et1+1);
    if (dom.find(".") == std::string::npos)
    {
        return false;
    }

    user = email.substr(0, et1);
    domain = dom;

    return true;
}

int main()
{
    std::string str;
    std::string user;
    std::string domain;

    std::cout << "Unesite email: ";
    std::getline(std::cin, str);

    if (split_email(str, user, domain))
    {
        std::cout << "korisnik: " << user;
        std::cout << ", domena: " << domain;
    }
    else
    {
        std::cout << "Neispravna adresa";
    }

    return 0;
}
