#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <utility>

using namespace std;

class ReadingManager {
public:
  void Read(int user_id, int page_count) {
      if (users.count(user_id) == 0) {
          users[user_id] = page_count;
          if (page_users.count(page_count)) {
              ++page_users[page_count];
          } else {
              page_users[page_count] = 1;
          }
      } else {
          --page_users[users[user_id]];
          if (page_users[users[user_id]] == 0) {
              page_users.erase(users[user_id]);
          }
          users[user_id] = page_count;
          ++page_users[users[user_id]];

      }
  }

  double Cheer(int user_id) const {
      if (users.count(user_id) == 0) {
          return 0;
      }
      auto it = page_users.lower_bound(users.at(user_id));
      if (users.size() == 1 || it == page_users.end()) {
          return 1;
      }
      if (it == page_users.begin()) {
          return 0;
      }
      double sum = 0;
      for (auto i = page_users.begin(); i != it; ++i) {
          sum += i->second;
      }
      return sum / (users.size() - 1);
  }

private:
  // id page users less pages
  map <int, int> users;
  // page users_count
  map <int, int> page_users;
};


int main() {
  // Для ускорения чтения данных отключается синхронизация
  // cin и cout с stdio,
  // а также выполняется отвязка cin от cout
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}
