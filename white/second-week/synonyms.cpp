#include <iostream>
#include <map>
#include <set>
#include <string>

int main(int argc, char const *argv[]) {
    std::map<std::string, std::set<std::string>> synonyms;
    int count;
    std::cin >> count;

    for (size_t i = 0; i < count; i++) {
        std::string operation, word1;
        std::cin >> operation >> word1;

        if (operation == "COUNT") {
            std::cout << synonyms[word1].size() << '\n';
        }
        else if (operation == "ADD") {
            std::string word2;
            std::cin >> word2;
            synonyms[word1].insert(word2);
            synonyms[word2].insert(word1);
        }
        else if (operation == "CHECK") {
            std::string word2;
            std::cin >> word2;
            if (synonyms[word1].count(word2)) {
                std::cout << "YES" << '\n';
            }
            else {
                std::cout << "NO" << '\n';
            }
        }
    }
    return 0;
}
