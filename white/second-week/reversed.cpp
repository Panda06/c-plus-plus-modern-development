#include <vector>
#include <iostream>
std::vector<int> Reversed(const std::vector<int>& v){
    std::vector<int> a;
    for (int i = v.size()-1; i >= 0; --i) {
        a.push_back(v[i]);
    }
    return a;
}
