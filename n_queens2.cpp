// 52. N-Queens II (hard)
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
  vector<int> u, d1, d2;
  int totalNQueens(int n) {
    u = vector<int>(n, 0);
    d1 = vector<int>(n * 2 - 1, 0);
    d2 = vector<int>(n * 2 - 1, 0);
    vector<string> tmp;
    string s;
    int ans = 0;
    for (int i = 0; i < n; ++i) s.push_back('.');
    for (int i = 0; i < n; ++i) tmp.push_back(s);
    solve(0, n, tmp, ans);
    return ans;
  }
  bool check(int i, int j, int n) {
    if (!u[j] && !d1[i + j] && !d2[n - 1 - i + j]) return true;
    else return false;
  }
  void put(int i, int j, int n, vector<string>& tmp) {
    tmp[i][j] = 'Q';
    u[j] = 1;
    d1[i + j] = 1;
    d2[n - 1 - i + j] = 1;
  }
  void rem(int i, int j, int n, vector<string>& tmp) {
    tmp[i][j] = '.';
    u[j] = 0;
    d1[i + j] = 0;
    d2[n - 1 - i + j] = 0;
  }
  void solve(int row, int n, vector<string>& tmp, int& ans) {
    if (row == n) {
      ans++;
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (check(row, i, n)) {
        put(row, i, n, tmp);
        solve(row + 1, n, tmp, ans);
        rem(row, i, n, tmp);
      }
    }
  }
};

int main() {
  Solution a;
  cout << a.totalNQueens(5) << endl;

  return 0;
}
