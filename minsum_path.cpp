// 64. Minimum Path Sum (medium)
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
  int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));
    for (int i = 0; i <= n; ++i) for (int j = 0; j <= m; ++j) dp[i][j] = 1e9;
    dp[1][1] = grid[0][0];
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i - 1][j - 1]);
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i - 1][j - 1]);
      }
    }
    return dp[n][m];
  }
};

int main() {
  Solution a;
  vector<vector<int>> b = {{1, 2, 1}, {3, 1, 1}, {3, 4, 2}};
  cout << a.minPathSum(b) << endl;

  return 0;
}
