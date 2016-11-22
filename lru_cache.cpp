// 146. LRU Cache (hard)
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

class LRUCache {
private:
  int _capacity;
  list<pair<int, int>> lru;
  map<int, list<pair<int, int>>::iterator> keys;
public:
  LRUCache(int capacity) : _capacity(capacity) {}

  int get(int key) {
    auto it = keys.find(key);
    if (it != keys.end()) {
      int val = (*it->second).second;
      lru.erase(it->second);
      lru.emplace_front(key, val);
      keys[key] = lru.begin();
      return val;
    }
    return -1;
  }

  void set(int key, int value) {
    auto it = keys.find(key);
    if (it == keys.end() && keys.size() == _capacity) {
      int k = lru.back().first;
      lru.pop_back();
      keys.erase(keys.find(k));
    }
    if (it != keys.end())
      lru.erase(it->second);
    lru.emplace_front(key, value);
    keys[key] = lru.begin();
  }

  void print() {
    for (auto& it: lru)
      cout << "[" << it.first << "," << it.second << "] ";
    cout << endl;
  }
};

int main() {
  LRUCache a(2);
  a.set(2, 1);
  a.set(2, 2);
  cout << a.get(2) << endl;
  a.set(1, 1);
  a.set(4, 1);
  cout << a.get(2) << endl;
  a.print();

  return 0;
}
