// 79. Word Search (medium)
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
  bool bt(int pos, int i, int j, vector<vector<bool>> u, string word, vector<vector<char>>& board) {
    if (pos >= word.size()) return true;
    int n = board.size(), m = board[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m || u[i][j])
      return false;
    bool res = false;
    if (board[i][j] == word[pos]) {
      u[i][j] = true;
      if (bt(pos + 1, i - 1, j, u, word, board) || bt(pos + 1, i + 1, j, u, word, board) ||
        bt(pos + 1, i, j - 1, u, word, board) || bt(pos + 1, i, j + 1, u, word, board))
        res = true;
      u[i][j] = false;
    }
    return res;
  }
  bool exist(vector<vector<char>>& board, string word) {
    if (board.empty()) return false;
    int n = board.size(), m = board[0].size();
    if (word.size() > n * m) return false;
    if (word.size() == 0) return true;
    vector<vector<bool>> u(n, vector<bool> (m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (bt(0, i, j, u, word, board)) return true;
      }
    }
    return false;
  }
};

int main() {
  Solution a;
  vector<vector<char>> b = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  cout << a.exist(b, "ABCCED") << endl;
  cout << a.exist(b, "SEE") << endl;
  cout << a.exist(b, "ABCB") << endl;

  return 0;
}
