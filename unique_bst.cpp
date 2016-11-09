// 96. Unique Binary Search Trees (medium)
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
  int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        dp[i] += dp[j] * dp[i - 1 - j];
      }
    }
    return dp[n];
  }
};

int main() {
  Solution a;
  cout << a.numTrees(3) << endl;
  cout << a.numTrees(5) << endl;

  return 0;
}
