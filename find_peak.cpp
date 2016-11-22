// 162. Find Peak Element
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
  bool peak(int i, vector<int>& nums) {
    return (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]);
  }
  int findPeakElement(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, mid;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (mid == 0) {
        if (nums.size() > 1 && nums[mid] < nums[mid + 1]) mid++;
        break;
      } else if (mid == nums.size() - 1 || peak(mid, nums)) break;
      else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) l = mid + 1;
      else r = mid - 1;
    }
    return mid;
  }
};

int main() {
  Solution a;
  vector<int> b = {1, 2, 3, 1}, c = {1, 3, 2, 1, 4, 5, 3, 7};
  cout << a.findPeakElement(b) << endl;
  cout << a.findPeakElement(c) << endl;

  return 0;
}
