// 59. Spiral Matrix II (medium)
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
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int> (n));
    if (n == 0) return ans;
    int top = 0, right = n - 1, bot = n - 1, left = 0, num = 1;
    while (true) {
      for (int i = left; i <= right; ++i) ans[top][i] = num++;
      top++;
      if (top > bot) break;
      for (int i = top; i <= bot; ++i) ans[i][right] = num++;
      right--;
      if (left > right) break;
      for (int i = right; i >= left; --i) ans[bot][i] = num++;
      bot--;
      if (left > right) break;
      for (int i = bot; i >= top; --i) ans[i][left] = num++;
      left++;
      if (top > bot) break;
    }
    return ans;
  }
};

int main() {
  Solution a;
  for (auto& x: a.generateMatrix(4)) {
    for (auto& y: x) {
      cout << y << ' ';
    }
    cout << endl;
  }

  return 0;
}
