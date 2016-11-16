// 127. Word Ladder (medium)
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <queue>

using namespace std;
typedef long long ll;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    int ans = 1;
    queue<string> can, cur;
    cur.push(beginWord);
    wordList.erase(beginWord);
    while (!cur.empty()) {
      while (!cur.empty()) {
        beginWord = cur.front();
        cur.pop();
        for (int i = 0; i < endWord.size(); ++i) {
          string tmp = beginWord;
          for (char c = 'a'; c <= 'z'; ++c) {
            tmp[i] = c;
            if (tmp == endWord) return ans + 1;
            if (tmp != beginWord && wordList.find(tmp) != wordList.end()) {
              can.push(tmp);
              wordList.erase(tmp);
            }
          }
        }
      }
      swap(cur, can);
      ans++;
    }
    return 0;
  }
};

int main() {
  Solution a;
  unordered_set<string> b = {"hot","dot","dog","lot","log"};
  cout << a.ladderLength("hit", "cog", b) << endl;

  return 0;
}
