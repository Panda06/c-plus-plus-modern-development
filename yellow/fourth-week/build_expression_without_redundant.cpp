#include <iostream>
#include <deque>
#include <string>
#include <vector>

struct OpAndNum {
    int number = 0;
    char operation = 0;
};

int main(int argc, char const *argv[]) {
    int number;
    std::cin >> number;
    int count;
    std::cin >> count;
    std::vector<OpAndNum> v(count);
    for (size_t i = 0; i < count; i++) {
        std::cin >> v[i].operation >> v[i].number;
    }
    std::deque<std::string> expression;
    char last_type = '/';
    expression.push_back(std::to_string(number));
    for (const auto& el : v) {
        if ((el.operation == '*' || el.operation == '/') &&
            (last_type == '+' || last_type == '-') ) {
            expression.push_front("(");
            expression.push_back(")");
        }
        expression.push_back(" " + std::string(1, el.operation));
        expression.push_back(" ");
        expression.push_back(std::to_string(el.number));
        last_type = el.operation;
    }
    for (const auto& s : expression) {
        std::cout << s;
    }
    return 0;
}
