#include <iostream>
#include <string>
#include <vector>

#define ADD "ADD"
#define NEXT "NEXT"
#define DUMP "DUMP"

void dump(const std::vector<std::string>& plans) {
    std::cout << plans.size() << ' ';
    for(const auto &plan: plans) {
        std::cout << plan << ' ';
    }
    std::cout << '\n';
}


void next(std::vector<std::vector<std::string>>& plans, const int& days) {
    if (days < plans.size()) {
        for (size_t i = days; i < plans.size(); i++) {
            plans[days-1].insert(end(plans[days-1]), begin(plans[i]), end(plans[i]));
        }
    }
    plans.resize(days);
}
int main() {
    std::vector<int> daysInMonth = {
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31 };
    int current = 0;
    std::vector<std::vector<std::string>> monthPlans(daysInMonth[current]);
    int n;
    std::cin >> n;
    for (size_t i = 0; i < n; i++) {
        std::string cmd;
        std::cin >> cmd;
        if (cmd == ADD) {
            int day;
            std::string plan;
            std::cin >> day >> plan;
            monthPlans[day-1].push_back(plan);
        }
        else if (cmd == DUMP) {
            int day;
            std::cin >> day;
            dump(monthPlans[day-1]);
        }
        else if(cmd == NEXT){
            ++current;
            current %= 12;
            next(monthPlans, daysInMonth[current]);
        }
    }
    return 0;
}
