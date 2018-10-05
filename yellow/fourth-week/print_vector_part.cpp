#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void PrintVectorPart(const std::vector<int>& numbers) {
    auto it = find_if(begin(numbers), end(numbers),
                      [](int number) {
                          return number < 0;
                      });
    for(auto i = it; i != begin(numbers);) {
        std::cout << *(--i) << ' ';
    }
}
