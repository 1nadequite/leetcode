// 152. Maximum Product Subarray (medium)
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
  int maxProduct(vector<int>& nums) {
    int ans = nums[0], mx = nums[0], mn = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      int tmx = mx, tmn = mn;
      mx = max(max( nums[i], nums[i] * tmx ), nums[i] * tmn);
      mn = min(min( nums[i], nums[i] * tmx ), nums[i] * tmn);
      ans = max(ans, mx);
    }
    return ans;
  }
};

int main() {
  Solution a;
  vector<int> b = {2, 3, -2, 4}, c = {-1, 2, 2, -3, 2, 4};
  cout << a.maxProduct(b) << endl;
  cout << a.maxProduct(c) << endl;

  return 0;
}
