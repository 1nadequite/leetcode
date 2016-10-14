// 47. Permutations II (medium)
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
  void bt(int sz, vector<int>& tmp, vector<int>& u, const vector<int>& nums, vector<vector<int>>& ans) {
    if (sz == nums.size()) {
      ans.push_back(tmp);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (!u[i] && (i == 0 || nums[i] != nums[i - 1] || u[i - 1])) {
        tmp.push_back(nums[i]);
        u[i] = 1;
        bt(sz + 1, tmp, u, nums, ans);
        tmp.pop_back();
        u[i] = 0;
      }
    }
  }
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> tmp, u(nums.size(), 0);
    sort(nums.begin(), nums.end());
    bt(0, tmp, u, nums, ans);
    return ans;
  }
};

int main() {
  Solution a;
  vector<int> b = {-1, 2, 0, -1, 1, 0, 1};
  for (auto x: a.permuteUnique(b)) {
    for (auto y: x) {
      cout << y << ' ';
    }
    cout << endl;
  }

  return 0;
}
