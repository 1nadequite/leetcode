// 139. Word Break (medium)
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;
typedef long long ll;

class Solution {
public:
  bool wordBreak(string s, unordered_set<string>& wordDict) {
    if (wordDict.size() == 0) return false;
    vector<bool> f(s.size() + 1, false);
    f[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (f[j]) {
          string word = s.substr(j, i - j);
          if (wordDict.find(word) != wordDict.end()) {
            f[i] = true;
            break;
          }
        }
      }
    }
    return f[s.size()];
  }
};

int main() {
  Solution a;
  string s = "bccdbacdbdacddabbaaaadababadad";
  unordered_set<string> us = {"cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba","aa","bd","abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b","bcc","bcd","cd","cbca","bbd","ddd","dabb","ab","acd","a","bbcc","cdcbd","cada","dbca","ac","abacd","cba","cdb","dbac","aada","cdcda","cdc","dbc","dbcb","bdb","ddbdd","cadaa","ddbc","babb"};
  cout << a.wordBreak(s, us) << endl;

  return 0;
}
