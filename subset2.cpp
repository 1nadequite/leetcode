// 90. Subsets II (medium)
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
  void bt(int pos, vector<int>& tmp, const vector<int>& nums, vector<vector<int>>& ans) {
    if (pos > nums.size()) return;
    ans.push_back(tmp);
    for (int i = pos; i < nums.size(); ++i) {
      tmp.push_back(nums[i]);
      bt(i + 1, tmp, nums, ans);
      tmp.pop_back();
      while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    bt(0, tmp, nums, ans);
    /*for (int i = 0; i < nums.size(); ++i) {
      tmp.push_back(nums[i]);
      bt(i + 1, tmp, nums, ans);
      tmp.pop_back();
      while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
    }*/
    return ans;
  }
};

int main() {
  Solution a;
  vector<int> b = {1, 2, 2};
  for (auto& x: a.subsetsWithDup(b)) {
    for (auto& y: x) {
      cout << y << ' ';
    }
    cout << endl;
  }

  return 0;
}
