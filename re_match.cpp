// 10. Regular Expression Matching (hard)
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
  bool isMatch(string s, string p) {
    cout << s << ' ' << p << endl;
    int ns = s.size(), np = p.size();
    vector<vector<bool>> dp(np + 1, vector<bool> (ns + 1, false));

    dp[0][0] = true;
    for (int i = 2; i <= np; ++i)
      if (p[i - 1] == '*')
        dp[i][0] = dp[i - 2][0];

    for (int j = 1; j <= ns; ++j) {
      for (int i = 1; i <= np; ++i) {
        if (p[i - 1] == '*') {
          if (dp[i - 2][j] || ((p[i - 2] == s[j - 1] || p[i - 2] == '.') && dp[i][j - 1]))
            dp[i][j] = true;
        } else {
          if (p[i - 1] == s[j - 1] || p[i - 1] == '.')
            dp[i][j] = dp[i - 1][j - 1];
        }
      }
    }
    for (int i = 0; i <= np; ++i) {
      for (int j = 0; j <= ns; ++j) {
        cout << dp[i][j] << ' ';
      }
      cout << endl;
    }
    return dp[np][ns];
  }
};

int main() {
  Solution a;
  cout << a.isMatch("cbba", "ab*ac*a") << endl;
  cout << a.isMatch("aa","aa") << endl;
  cout << a.isMatch("aaa","aaaa") << endl;
  cout << a.isMatch("aa", "a*") << endl;
  cout << a.isMatch("aa", ".*") << endl;
  cout << a.isMatch("ab", ".*") << endl;
  cout << a.isMatch("aab", "c*a*b") << endl;

  return 0;
}
