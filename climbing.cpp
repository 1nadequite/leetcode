// 70. Climbing Stairs (easy)
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
  int climbStairs(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i < n + 1; ++i)
      dp[i] += (dp[i - 1] + dp[i - 2]);
    return dp[n];
  }
};

int main() {
  Solution a;
  cout << a.climbStairs(6) << endl;

  return 0;
}
