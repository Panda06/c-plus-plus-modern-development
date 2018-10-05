#include <string>
#include <vector>
using namespace std;

#define concate(num) id##num
#define getnum(line) concate(line)
#define UNIQ_ID getnum(__LINE__) // Реализуйте этот макрос так, чтобы функция main компилировалась

int main() {
  int UNIQ_ID = 0;
  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}
