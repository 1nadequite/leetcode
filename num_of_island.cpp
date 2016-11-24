// 200. Number of Islands
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
  void island(int i, int j, int n, int m, vector<vector<char>>& grid) {
    if (grid[i][j] == '0' || grid[i][j] == '2') return;
    grid[i][j] = '2';
    if (i >= 1) island(i - 1, j, n, m, grid);
    if (j >= 1) island(i, j - 1, n, m, grid);
    if (i < n - 1) island(i + 1, j, n, m, grid);
    if (j < m - 1) island(i, j + 1, n, m, grid);
  }
  int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size(), ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '1') {
          island(i, j, n, m, grid);
          ans++;
        }
        if (grid[i][j] == '2') grid[i][j] = '1';
      }
    }
    return ans;
  }
};

int main() {
  Solution a;
  vector<vector<char>> b = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
  cout << a.numIslands(b) << endl;

  return 0;
}
