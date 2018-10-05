#include <exception>
#include <iostream>
#include <map>
#include <string>

template <class Key, class Value>
Value& GetRefStrict(std::map<Key, Value>& m, Key k) {
    if (m.count(k)) {
        return m.at(k);
    }
    throw std::runtime_error("");
}

int main(int argc, char const *argv[]) {
    std::map<int, std::string> m = {{0, "value"}};
    std::string& item = GetRefStrict(m, 0);
    item = "newvalue";
    std::cout << m[0] << std::endl;
    return 0;
}
