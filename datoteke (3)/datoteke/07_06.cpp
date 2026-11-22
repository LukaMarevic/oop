#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct WordCount
{
    std::string word;
    int count;
};

std::string clean(const std::string& word)
{
    std::string result;
    for (char c : word)
    {
        if (std::isalpha(static_cast<unsigned char>(c)))
        {
            result += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
    }
    return result;
}

int main()
{
    std::ifstream in("./tekst.txt");
    if (!in)
    {
        std::cout << "ne mogu otvoriti datoteku.\n";
        return 1;
    }

    std::map<std::string, int> freq;
    std::string word;
    while (in >> word)
    {
        std::string w = clean(word);
        if (w.empty())
        {
            continue;
        }
        ++freq[w];
    }

    std::cout << "razlicitih rijeci: " << freq.size() << '\n';

    auto it = freq.find("alice");
    std::cout << "alice: " << (it != freq.end() ? it->second : 0) << '\n';

    std::vector<WordCount> words;
    for (const auto& p : freq)
    {
        words.push_back({p.first, p.second});
    }

    std::sort(words.begin(), words.end(), [](const WordCount& a, const WordCount& b) {
        if (a.count != b.count)
        {
            return a.count > b.count;
        }
        return a.word < b.word;
    });

    for (std::size_t i = 0; i < 5 && i < words.size(); ++i)
    {
        std::cout << words[i].word << ": " << words[i].count << '\n';
    }
    return 0;
}
