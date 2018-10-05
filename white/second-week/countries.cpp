#include <iostream>
#include <string>
#include <map>

#define CHANGE_CAPITAL "CHANGE_CAPITAL"
#define RENAME "RENAME"
#define ABOUT "ABOUT"
#define DUMP "DUMP"

void PrintMap(const std::map<std::string, std::string>& countries) {
    if (countries.size() == 0) {
        std::cout << "There are no countries in the world";
    }
    for(const auto& item : countries) {
        std::cout << item.first << "/" << item.second << ' ';
    }
    std::cout << '\n';
}
int main() {
    int n;
    std::cin >> n;
    std::map<std::string, std::string> countries;
    for (size_t i = 0; i < n; i++) {
        std::string operation;
        std::cin >> operation;
        if (operation == DUMP) {
            PrintMap(countries);
        }
        else {
            std::string country;
            std::cin >> country;
            if (operation == ABOUT) {
                std::cout << "Country " << country;
                if (countries.count(country) == 0) {
                    std::cout << " doesn't exist" << std::endl;
                }
                else {
                    std::cout << " has capital " << countries[country] << std::endl;
                }
            }
            else if (operation == RENAME) {
                std::string new_country;
                std::cin >> new_country;
                if (country == new_country ||
                    countries.count(country) == 0 ||
                    countries.count(new_country) > 0) {
                    std::cout << "Incorrect rename, skip" << std::endl;
                }
                else {
                    countries[new_country] = countries[country];
                    std::cout << "Country " << country <<  " with capital "
                              << countries[country] <<  " has been renamed to "
                              << new_country << std::endl;
                    countries.erase(country);
                }
            }
            else if (operation == CHANGE_CAPITAL) {
                std::string new_capital;
                std::cin >> new_capital;
                if (countries.count(country) == 0) {
                    countries[country] = new_capital;
                    std::cout << "Introduce new country " << country
                              << " with capital " << new_capital << std::endl;
                }
                else if (countries[country] == new_capital) {
                    std::cout << "Country " << country
                              << " hasn't changed its capital" << '\n';
                }
                else {
                    std::cout << "Country " << country
                              << " has changed its capital from "
                              << countries[country] << " to " << new_capital << '\n';
                    countries[country] = new_capital;

                }
            }
        }
    }
    return 0;
}
