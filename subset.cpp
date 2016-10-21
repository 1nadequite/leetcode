// 78. Subsets (medium)
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
  // recursion
  void bt(int pos, vector<int>& tmp, const vector<int>& nums, vector<vector<int>>& ans) {
    if (pos > nums.size()) return;
    ans.push_back(tmp);
    for (int i = pos; i < nums.size(); ++i) {
      tmp.push_back(nums[i]);
      bt(i + 1, tmp, nums, ans);
      tmp.pop_back();
    }
  }
  vector<vector<int>> subsets1(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> tmp;
    bt(0, tmp, nums, ans);
    return ans;
  }
  // bit manipulation
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size(), nsub = 1 << n;
    for (int i = 0; i < nsub; ++i) {
      vector<int> tmp;
      for (int j = 0; j < n; ++j) {
        if ((1 << j) & i) {
          tmp.push_back(nums[j]);
        }
      }
      ans.push_back(tmp);
    }
    return ans;
  }
};

int main() {
  Solution a;
  vector<int> b = {1, 2, 3};
  for (auto& x: a.subsets(b)) {
    for (auto& y: x) {
      cout << y << ' ';
    }
    cout << endl;
  }

  return 0;
}
