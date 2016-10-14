// 46. Permutations (medium)
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
  void bt(int sz, vector<int>& nums, vector<vector<int>>& ans) {
    int n = nums.size();
    if (sz == n) {
      ans.push_back(nums);
      return;
    }
    for (int i = sz; i < n; ++i) {
      swap(nums[sz], nums[i]);
      bt(sz + 1, nums, ans);
      swap(nums[sz], nums[i]);
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    bt(0, nums, ans);
    return ans;
  }
};

int main() {
  Solution a;
  vector<int> b = {1, 2, 3};
  for (auto x: a.permute(b)) {
    for (auto y: x) {
      cout << y << ' ';
    }
    cout << endl;
  }

  return 0;
}
