// 240. Search a 2D Matrix II
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
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    if (n == 0) return false;
    int m = matrix[0].size(), i = 0, j = m - 1;
    while (i < n && j >= 0) {
      if (matrix[i][j] == target) return true;
      else if (matrix[i][j] < target) i++;
      else j--;
    }
    return false;
  }
};

int main() {
  Solution a;
  vector<vector<int>> b = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
  cout << a.searchMatrix(b, 5) << endl;
  cout << a.searchMatrix(b, 20) << endl;

  return 0;
}
