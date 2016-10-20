// 73. Set Matrix Zeroes (medium)
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
  void findFree(int n, int m, int& x, int& y, vector<vector<int>>& matrix) {
    for (int i = 0; i < n; ++i) {
      bool flag = true;
      for (int j = 0; j < m; ++j)
        if (matrix[i][j] == 0)
          flag = false;
      if (flag) x = i;
    }
    for (int i = 0; i < m; ++i) {
      bool flag = true;
      for (int j = 0; j < n; ++j)
        if (matrix[j][i] == 0)
          flag = false;
      if (flag) y = i;
    }
  }
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    int n = matrix.size(), m = matrix[0].size();
    int x = -1, y = -1;
    findFree(n, m, x, y, matrix);
    if (x == -1 || y == -1) {
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
          matrix[i][j] = 0;
      return;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (matrix[i][j] == 0) {
          if (i != x) matrix[i][y] = 0;
          if (j != y) matrix[x][j] = 0;
        }
      }
    }
    for (int i = 0; i < n; ++i)
      if (matrix[i][y] == 0 && i != x)
        for (int j = 0; j < m; ++j)
          matrix[i][j] = 0;
    for (int i = 0; i < m; ++i)
      if (matrix[x][i] == 0 && i != y)
        for (int j = 0; j < n; ++j)
          matrix[j][i] = 0;
  }
};

int main() {
  Solution a;
  vector<vector<int>> b = {{0,0,0,5}, {4,3,1,4}, {0,1,1,4}, {1,2,1,3}, {0,0,1,1}};
  a.setZeroes(b);
  for (auto& x: b) {
    for (auto& y: x) {
      cout << y << ' ';
    }
    cout << endl;
  }

  return 0;
}
