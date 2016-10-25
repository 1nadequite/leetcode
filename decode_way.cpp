// 91. Decode Ways (medium)
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
  int numDecodings(string s) {
    int n = s.size();
    if (n == 0 || s[0] == '0') return 0;
    vector<int> dp(n + 1, 1);
    for (int i = 1; i < n; ++i) {
      int x = (s[i - 1] - '0') * 10 + (s[i] - '0');
      if (s[i] == '0') {
        if (s[i - 1] != '1' && s[i - 1] != '2') return 0;
        else dp[i + 1] = dp[i - 1];
      } else if (x > 10 && x < 27) {
        dp[i + 1] = dp[i] + dp[i - 1];
      } else {
        dp[i + 1] = dp[i];
      }
    }
    return dp[n];
  }
};

int main() {
  Solution a;
  cout << a.numDecodings("12") << endl;
  cout << a.numDecodings("2341") << endl;
  cout << a.numDecodings("1111") << endl;

  return 0;
}
