#include <algorithm>
#include <string>

class ReversibleString {
private:
    std::string s;
public:
    ReversibleString() {}
    ReversibleString(const std::string& _s): s(_s){}
    void Reverse() {
        reverse(s.begin(), s.end());
    }
    std::string ToString() const {
        return s;
    }
};
