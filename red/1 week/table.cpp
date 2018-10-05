#include "test_runner.h"

using namespace std;

template <class T>
class Table {
private:
    size_t h;
    size_t w;
    std::vector<std::vector<T>> table;
public:
    Table(size_t _h, size_t _w) : h(_h), w(_w) {
        Resize(h, w);
    }
    void Resize(size_t _h, size_t _w) {
        h = _h;
        w = _w;
        table.resize(h);
        for (auto& row : table) {
            row.resize(w);
        }
    }
    pair<size_t, size_t> Size() const {
        return make_pair(h, w);
    }
    const std::vector<T>& operator[] (int i) const {
        return table[i];
    }
    std::vector<T>& operator[] (int i) {
        return table[i];
    }
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
