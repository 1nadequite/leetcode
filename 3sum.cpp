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
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      vector<vector<int>> ans;
      for (int i = 0; i < n - 2; ++i) {
        int l = i + 1, r = n - 1;
        while (l < r) {
          if (nums[i] + nums[l] + nums[r] == 0) {
            ans.push_back({nums[i], nums[l], nums[r]});
            while (nums[l] == nums[l + 1])
              l++;
            while (nums[r] == nums[r - 1])
              r--;
            l++; r--;
          }
          else if (nums[i] + nums[l] + nums[r] > 0)
            r--;
          else
            l++;
        }
        while (nums[i] == nums[i + 1])
          ++i;
      }
      return ans;
    }
};

int main() {
  Solution a;
  vector<int> b = {-1, 1, 0, 2, -1, -4};
  for (auto& x: a.threeSum(b)) {
    for (auto& y : x) {
      cout << y << ' ';
    }
    cout << endl;
  }

  return 0;
}
