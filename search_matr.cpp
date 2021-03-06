// 74. Search a 2D Matrix (medium)
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
  // O(n + m);
  bool searchMatrix1(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int n = matrix.size(), m = matrix[0].size();
    int i = 0, j = m - 1;
    while (i < n && j >= 0) {
      if (matrix[i][j] == target) return true;
      if (matrix[i][j] > target) j--;
      else i++;
    }
    return false;
  }
  // O(log(n*m))
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int n = matrix.size(), m = matrix[0].size();
    int l = 0, r = n * m - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int elem = matrix[mid / m][mid % m];
      if (elem == target) return true;
      if (elem > target) r = mid - 1;
      else l = mid + 1;
    }
    return false;
  }
};

int main() {
  Solution a;
  vector<vector<int>> b = {{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};
  cout << a.searchMatrix(b, 3) << endl;
  cout << a.searchMatrix(b, 12) << endl;

  return 0;
}
