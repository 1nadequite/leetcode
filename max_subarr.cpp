// 53. Maximum Subarray
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
  // the naive method O(n^2)
  int maxSubArray1(vector<int>& nums) {
    int ans = nums[0];
    for (int i = 0; i < nums.size(); ++i) {
      int sum = 0;
      for (int j = i; j < nums.size(); ++j) {
        sum += nums[j];
        ans = max(ans, sum);
      }
    }
    return ans;
  }
  // divide and conquer O(n*log(n))
  int maxCrossSum(const vector<int>& nums, int l, int m, int r) {
    int sum = 0, left_sum = -1e9;
    for (int i = m; i >= l; --i) {
      sum += nums[i];
      left_sum = max(left_sum, sum);
    }
    sum = 0;
    int right_sum = -1e9;
    for (int i = m + 1; i <= r; ++i) {
      sum += nums[i];
      right_sum = max(right_sum, sum);
    }
    return left_sum + right_sum;
  }
  int maxSubSum(const vector<int>& nums, int l, int r) {
    if (l == r) return nums[l];
    int mid = (l + r) >> 1;
    return max(max(maxSubSum(nums, l, mid), maxSubSum(nums, mid + 1, r)), maxCrossSum(nums, l, mid, r));
  }
  int maxSubArray2(vector<int>& nums) {
    return maxSubSum(nums, 0, nums.size() - 1);
  }
  // O(n)
  int maxSubArray3(vector<int>& nums) {
    int ans = nums[0], sum = 0, min_sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      ans = max(ans, sum - min_sum);
      min_sum = min(min_sum, sum);
    }
    return ans;
  }
  // Kadane's algorithm O(n)
  int maxSubArray(vector<int>& nums) {
    int ans = nums[0], sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      ans = max(ans, sum);
      sum = max(sum, 0);
    }
    return ans;
  }
};

int main() {
  Solution a;
  vector<int> b = {-2,1,-3,4,-1,2,1,-5,4};
  vector<int> c = {-1, -2, -3};
  cout << a.maxSubArray(b) << endl;
  cout << a.maxSubArray(c) << endl;

  return 0;
}
