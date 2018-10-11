#include "test_runner.h"
#include "profile.h"
#include <functional>
#include <future>
#include <map>
#include <sstream>
#include <string>
#include <thread>
using namespace std;

struct Stats {
  map<string, int> word_frequences;

  void operator += (const Stats& other) {
      for (const auto& [word, count] : other.word_frequences) {
          word_frequences[word] += count;
      }
  }
};

Stats ExploreLine(const set<string>& key_words, const string& line) {
    Stats result;
    stringstream iss(line);
    string word;
    while(getline(iss, word, ' ')) {
        if (key_words.count(word)) {
            result.word_frequences[word]++;
        }
    }
    return result;
}

Stats ExploreKeyWordsSingleThread(
  const set<string>& key_words, istream& input
) {
  Stats result;
  for (string line; getline(input, line); ) {
    result += ExploreLine(key_words, line);
  }
  return result;
}

Stats ExploreLines(const set<string>& key_words, const vector<string>& lines) {
    Stats result;
    for(auto& line : lines) {
        result += ExploreLine(key_words, line);
    }
    return result;
}
Stats ExploreKeyWords(const set<string>& key_words, istream& input) {
  Stats result;
  int count = 0;
  auto n_thread =  thread::hardware_concurrency();
  vector<vector<string>> lines(n_thread);
  string line;

  while(getline(input, line)) {
      lines[count % n_thread].push_back(line);
      ++count;
  }

  vector<future<Stats>> futures;
  for(auto& thread_lines : lines) {
      futures.push_back(async(ExploreLines, ref(key_words), ref(thread_lines)));
  }
  for (auto& f: futures) {
      result += f.get();
  }
  return result;
}

void TestBasic() {
  const set<string> key_words = {"yangle", "rocks", "sucks", "all"};

  stringstream ss;
  ss << "this new yangle service really rocks\n";
  ss << "It sucks when yangle isn't available\n";
  ss << "10 reasons why yangle is the best IT company\n";
  ss << "yangle rocks others suck\n";
  ss << "Goondex really sucks, but yangle rocks. Use yangle\n";

  const auto stats = ExploreKeyWords(key_words, ss);
  const map<string, int> expected = {
    {"yangle", 6},
    {"rocks", 2},
    {"sucks", 1}
  };
  ASSERT_EQUAL(stats.word_frequences, expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestBasic);
}
