// 48. Rotate Image (medium)
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
  void move(int s, vector<vector<int>>& matrix) {
    int pr = matrix[s][s], n = matrix.size();
    for (int i = s + 1; i < n - s; ++i) swap(pr, matrix[s][i]);
    for (int i = s + 1; i < n - s; ++i) swap(pr, matrix[i][n - 1 - s]);
    for (int i = n - 2 - s; i >= 0 + s; --i) swap(pr, matrix[n - 1 - s][i]);
    for (int i = n - 2 - s; i >= 0 + s; --i) swap(pr, matrix[i][s]);
  }
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n < 2) return;
    for (int s = 0; s < n / 2; ++s) {
      int num_move = n - 1 - s * 2;
      while (num_move) {
        move(s, matrix);
        num_move--;
      }
    }
  }
};

int main() {
  Solution a;
  vector<vector<int>> b = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15,16}};
  a.rotate(b);
  for (auto& x : b) {
    for (auto& y : x) {
      cout << y << ' ';
    }
    cout << endl;
  }

  return 0;
}
