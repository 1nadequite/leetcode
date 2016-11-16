// 131. Palindrome Partitioning (medium)
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

class Solution {
public:
  bool palindrome(string& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      if (s[l] != s[r]) return false;
      l++; r--;
    }
    return true;
  }
  void bt(int i, int n, string& pal, string& s, vector<string>& tmp, vector<vector<string>>& ans) {
    pal.push_back(s[i]);
    if (i == n - 1 && palindrome(pal)) {
      tmp.push_back(pal);
      ans.push_back(tmp);
      tmp.pop_back();
      return;
    }
    if (i == n - 1 && !palindrome(pal)) return;
    if (palindrome(pal)) {
      tmp.push_back(pal);
      string st;
      bt(i + 1, n, st, s, tmp, ans);
      tmp.pop_back();
    }
    bt(i + 1, n, pal, s, tmp, ans);
  }
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    int n = s.size();
    if (n == 0) return ans;
    vector<string> tmp;
    string pal;
    bt(0, n, pal, s, tmp, ans);
    return ans;
  }
};

int main() {
  Solution a;
  string s = "aab";
  for (auto x: a.partition(s)) {
    for (auto y: x) {
      cout << y << ' ';
    }
    cout << endl;
  }

  return 0;
}
