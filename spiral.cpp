// 54. Spiral Matrix (medium)
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
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> ans;
    if (n == 0) return ans;
    int top = 0, right = m - 1, bot = n - 1, left = 0;
    while (true) {
      for (int i = left; i <= right; ++i) ans.push_back(matrix[top][i]);
      top++;
      if (top > bot) break;
      for (int i = top; i <= bot; ++i) ans.push_back(matrix[i][right]);
      right--;
      if (left > right) break;
      for (int i = right; i >= left; --i) ans.push_back(matrix[bot][i]);
      bot--;
      if (left > right) break;
      for (int i = bot; i >= top; --i) ans.push_back(matrix[i][left]);
      left++;
      if (top > bot) break;
    }
    return ans;
  }
};

int main() {
  Solution a;
  vector<vector<int>> b = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> c = {};
  for (auto& x: a.spiralOrder(c))
    cout << x << ' ' ;
  cout << endl;

  return 0;
}
