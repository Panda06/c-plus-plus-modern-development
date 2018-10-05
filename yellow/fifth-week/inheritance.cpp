#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    Animal(const string& _Name) : Name(_Name) {}

    const string Name;
};


class Dog : public Animal{
public:
    Dog(const string& _Name) : Animal(_Name){}

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};
