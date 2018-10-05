#include <iostream>
#include <map>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
    std::map<std::vector<std::string>, int> stops;
    int count = 1;
    int q;
    std::cin >> q;
    for (size_t i = 0; i < q; i++) {
        int n;
        std::cin >> n;
        std::vector<std::string> v;
        for (size_t i = 0; i < n; i++) {
            std::string s;
            std::cin >> s;
            v.push_back(s);
        }
        if (stops.count(v) == 0) {
            stops[v] = count;
            std::cout << "New bus " << count << '\n';
            ++count;
        }
        else {
            std::cout << "Already exists for " << stops[v] << '\n';
        }
    }
    return 0;
}
