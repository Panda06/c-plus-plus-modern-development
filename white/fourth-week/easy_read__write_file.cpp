#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[]) {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    if (input.is_open()) {
        std::string s;
        while (getline(input, s)) {
            output << s << '\n';
        }
    }
    return 0;
}
