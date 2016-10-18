// 63. Unique Paths II (medium)
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
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    if (n == 0) return 0;
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));
    if (obstacleGrid[0][0] == 0) dp[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (obstacleGrid[i - 1][j - 1] == 1) continue;
        if (i - 2 >= 0 && j - 1 >= 0 && obstacleGrid[i - 2][j - 1] == 0) dp[i][j] += dp[i - 1][j];
        if (i - 1 >= 0 && j - 2 >= 0 && obstacleGrid[i - 1][j - 2] == 0) dp[i][j] += dp[i][j - 1];
      }
    }
    return dp[n][m];
  }
};

int main() {
  Solution a;
  vector<vector<int>> b = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  cout << a.uniquePathsWithObstacles(b) << endl;

  return 0;
}
