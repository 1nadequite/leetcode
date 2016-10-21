// 77. Combinations (medium)
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
  void bt(int pos, int n, int k, vector<int>& tmp, vector<vector<int>>& ans) {
    if (tmp.size() == k) {
      ans.push_back(tmp);
      return;
    }
    for (int i = pos; i <= n; ++i) {
      tmp.push_back(i);
      bt(i + 1, n, k, tmp, ans);
      tmp.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> tmp;
    bt(1, n, k, tmp, ans);
    return ans;
  }
};

int main() {
  Solution a;
  for (auto& x: a.combine(4, 2)) {
    for (auto& y: x) {
      cout << y << ' ';
    }
    cout << endl;
  }

  return 0;
}
