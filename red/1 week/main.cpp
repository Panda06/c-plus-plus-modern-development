#include "deque.h"
#include <iostream>

void Print(const Deque<int>& d) {
    for (size_t i = 0; i < d.Size(); ++i) {
        std::cout << d[i] << ' ';
    }
    std::cout << '\n';
}
int main(int argc, char const *argv[]) {
    Deque<int> d;
    d.PushBack(2);
    d.PushFront(3);
    d.PushBack(4);
    d.PushFront(1);
    d.PushFront(0);
    Print(d);
    std::cout << d.Size() << '\n';
    return 0;
}
