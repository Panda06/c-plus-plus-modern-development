#include "test_runner.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <memory>
#include <set>
#include <utility>
#include <vector>

using namespace std;


struct Object {
    Object(size_t& id_, int priory_) : id(id_), priory(priory_) {}
    size_t id;
    int priory;
};

bool operator<(const Object& lhs, const Object& rhs) {
    return lhs.priory < rhs.priory || lhs.priory == rhs.priory && lhs.id < rhs.id;
}


template <typename T>
class PriorityCollection {
public:
  PriorityCollection() {
      objects.reserve(1'000'000);
      priory.reserve(1'000'000);
      is_valid.reserve(1'000'000);
  }
  /* тип, используемый для идентификаторов */
  using Id = size_t;

  // Добавить объект с нулевым приоритетом
  // с помощью перемещения и вернуть его идентификатор
  Id Add(T object) {
      Id id = objects.size();
      objects.push_back(move(object));
      priory.push_back(0);
      is_valid.push_back(true);
      ids.insert(Object(id, 0));
      return id;
  }

  // Добавить все элементы диапазона [range_begin, range_end)
  // с помощью перемещения, записав выданные им идентификаторы
  // в диапазон [ids_begin, ...)
  template <typename ObjInputIt, typename IdOutputIt>
  void Add(ObjInputIt range_begin, ObjInputIt range_end, IdOutputIt ids_begin) {
      //size_t start_id = objects.size();
      //move(range_begin, range_end, back_inserter(objects));
      //fill_n(back_inserter(priory), distance(range_begin, range_end), 0);
      //fill_n(back_inserter(is_valid), distance(range_begin, range_end), true);
      for (auto it = range_begin; it != range_end; it++ ) {
          *ids_begin = Add(move(*it));
          ids_begin++;
}
  }

  // Определить, принадлежит ли идентификатор какому-либо
  // хранящемуся в контейнере объекту
  bool IsValid(Id id) const {
      return is_valid[id];
  }

  // Получить объект по идентификатору
  const T& Get(Id id) const {
      return objects[id];
  }

  // Увеличить приоритет объекта на 1
  void Promote(Id id) {
      ids.erase(ids.find({id, priory[id]}));
      ++priory[id];
      ids.insert({id, priory[id]});
  }

  // Получить объект с максимальным приоритетом и его приоритет
  pair<const T&, int> GetMax() const {
      Object obj = *ids.rbegin();
      return {objects[obj.id], obj.priory};
  }

  // Аналогично GetMax, но удаляет элемент из контейнера
  pair<T, int> PopMax() {
      Object obj = move(*ids.rbegin());
      is_valid[obj.id] = false;
      ids.erase(prev(ids.end()));
      return { move(objects[obj.id]), obj.priory};
  }

private:
  // Приватные поля и методы
  vector<T> objects;
  vector<bool> is_valid;
  vector<int> priory;
  set<Object> ids;
};


class StringNonCopyable : public string {
public:
  using string::string;  // Позволяет использовать конструкторы строки
  StringNonCopyable(const StringNonCopyable&) = delete;
  StringNonCopyable(StringNonCopyable&&) = default;
  StringNonCopyable& operator=(const StringNonCopyable&) = delete;
  StringNonCopyable& operator=(StringNonCopyable&&) = default;
};

void TestNoCopy() {
  PriorityCollection<StringNonCopyable> strings;
  const auto white_id = strings.Add("white");
  const auto yellow_id = strings.Add("yellow");
  const auto red_id = strings.Add("red");

  strings.Promote(yellow_id);
  for (int i = 0; i < 2; ++i) {
    strings.Promote(red_id);
  }
  strings.Promote(yellow_id);
  {
    const auto item = strings.PopMax();
    ASSERT_EQUAL(item.first, "red");
    ASSERT_EQUAL(item.second, 2);
  }
  {
    const auto item = strings.PopMax();
    ASSERT_EQUAL(item.first, "yellow");
    ASSERT_EQUAL(item.second, 2);
  }
  {
    const auto item = strings.GetMax();
    ASSERT_EQUAL(item.first, "white");
    ASSERT_EQUAL(item.second, 0);
  }
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestNoCopy);
  return 0;
}
