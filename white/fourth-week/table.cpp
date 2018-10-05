#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[]) {
    int n, m;
    std::ifstream input("input.txt");
    if (input.is_open()) {
        input >> n >> m;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                int value;
                input >> value;
                input.ignore(1);
                std::cout << std::setw(10) << value;

                if (j < m-1) {
                    std::cout << " ";
                }
            }
            if (i < n-1) {
                std::cout << '\n';

            }
        }
    }
    return 0;
}
