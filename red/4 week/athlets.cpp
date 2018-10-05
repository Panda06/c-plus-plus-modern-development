#include <iostream>
#include <list>
#include <vector>

int main(int argc, char const *argv[]) {
    const int MAX = 100'000;

    std::list<int> athletes;
    std::vector<std::list<int>::iterator> positions(MAX + 1, athletes.end());

    int count_athletes;
    std::cin >> count_athletes;

    for (size_t i = 0; i < count_athletes; ++i) {
        int current_athlete, next_athlete;
        std::cin >> current_athlete >> next_athlete;
        positions[current_athlete] = athletes.insert(positions[next_athlete],
                                                     current_athlete);
    }
    for (auto el : athletes) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
    return 0;
}
