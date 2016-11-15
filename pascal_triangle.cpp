// 118. Pascal's Triangle (easy)
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
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    for (int i = 0; i < numRows; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (i == 0 || j == 0 || j == i) ans[i].push_back(1);
        else ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
      }
    }
    return ans;
  }
};

int main() {
  Solution a;
  for (auto& x: a.generate(5)) {
    for (auto& y: x) {
      cout << y << ' ';
    }
    cout << endl;
  }

  return 0;
}
