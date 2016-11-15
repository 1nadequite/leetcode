// 120. Triangle (medium)
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
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    for (int i = n - 2; i >= 0; --i)
      for (int j = 0; j <= i; ++j)
        triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
    return triangle[0][0];
  }
};

int main() {
  Solution a;
  vector<vector<int>> b = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  cout << a.minimumTotal(b) << endl;

  return 0;
}
