#include <vector>
#include <iostream>
void Reverse(std::vector<int>& v){
    std::vector<int> a;
    for (int i = v.size()-1; i >= 0; --i) {
        a.push_back(v[i]);
    }
    v = a;
}
