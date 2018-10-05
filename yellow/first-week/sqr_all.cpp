#include <iostream>
#include <map>
#include <utility>
#include <vector>


template<typename T>
T Sqr(T x) {
    return x * x;
}

template <class T>
std::vector<T> Sqr(std::vector<T>& v);

template <class Key, class Value>
std::map<Key, Value> Sqr(std::map<Key, Value>& m);

template <class First, class Second>
std::pair<First, Second> Sqr(std::pair<First, Second>& p);

template <class T>
std::vector<T> Sqr(std::vector<T>& v) {
    std::vector<T> res;
    for (auto& el : v) {
        res.push_back(Sqr(el));
    }
    return res;
}

template <class Key, class Value>
std::map<Key, Value> Sqr(std::map<Key, Value>& m) {
    for (auto& item : m) {
        m[item.first] = Sqr(item.second);
    }
    return m;
}

template <class First, class Second>
std::pair<First, Second> Sqr(std::pair<First, Second>& p) {
    return {Sqr(p.first), Sqr(p.second)};
}

int main(int argc, char const *argv[]) {
    std::vector<int> v = {1, 2, 3};
    std::cout << "vector:";
    for (int x : Sqr(v)) {
        std::cout << ' ' << x;
    }
    std::cout << std::endl;
    std::map<int, std::pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}
    };
    std::cout << "map of pairs:" << std::endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
    }
    return 0;
}
