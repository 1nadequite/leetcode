// 62. Unique Paths (medium)
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
  // O(n * m);
  int uniquePaths1(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int> (n + 1));
    dp[1][1] = 1;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]);
      }
    }
    return dp[m][n];
  }
  // O(n + m)
  int uniquePaths(int m, int n) {
    long long ans = 1;
    for (int i = m; i < (m + n - 1); ++i) {
      ans *= i;
      ans /= (i - m + 1);
    }
    return (int)ans;
  }
};

int main() {
  Solution a;
  cout << a.uniquePaths(3, 7) << endl;

  return 0;
}
