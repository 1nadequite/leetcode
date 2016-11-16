// 130. Surrounded Regions (medium)
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
  void bfs(int i, int j, int n, int m, vector<vector<char>>& board) {
    if (board[i][j] == 'O') {
      board[i][j] = 'C';
      if (i + 1 < n) bfs(i + 1, j, n, m, board);
      if (i > 1) bfs(i - 1, j, n, m, board);
      if (j + 1 < m) bfs(i, j + 1, n, m, board);
      if (j > 1) bfs(i, j - 1, n, m, board);
    }
  }
  void solve(vector<vector<char>>& board) {
    int n = board.size();
    if (n == 0) return;
    int m = board[0].size();
    for (int i = 0; i < n; ++i) {
      bfs(i, 0, n, m, board);
      if (m > 1) bfs(i, m - 1, n, m, board);
    }
    for (int j = 1; j < m - 1; ++j) {
      bfs(0, j, n, m, board);
      if (n > 1) bfs(n - 1, j, n, m, board);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (board[i][j] == 'C') board[i][j] = 'O';
        else if (board[i][j] == 'O') board[i][j] = 'X';
      }
    }
  }
};

int main() {
  Solution a;
  vector<vector<char>> b = {{'O', 'X', 'O', 'O'}, {'X', 'O', 'X', 'X'}, {'X', 'X', 'X', 'O'}, {'O', 'O', 'O', 'O'}, {'X', 'X', 'X', 'X'}};
  a.solve(b);
  for (auto x: b) {
    for (auto y: x) {
      cout << y;
    }
    cout << endl;
  }

  return 0;
}
