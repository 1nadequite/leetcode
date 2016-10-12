// 34. Search for a Range
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

class Solution {
  public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int n = nums.size();
      vector<int> ans = {-1, -1};
      int l = 0, r = n;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] >= target) r = mid;
        else l = mid + 1;
      }
      if (nums[r] == target) ans[0] = r;
      l = 0, r = n;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] > target) r = mid;
        else l = mid + 1;
      }
      if (nums[l - 1] == target) ans[1] = l - 1;
      return ans;
    }
};

int main() {
  Solution a;
  vector<int> b = {5, 7, 7, 8, 8, 9};
  vector<int> c = {3, 4, 5, 6};
  vector<int> d = {1, 2, 4};
  vector<int> e = {1};
  for (auto x: a.searchRange(b, 8))
    cout << x << ' ';
  cout << endl;
  for (auto x: a.searchRange(c, 4))
    cout << x << ' ';
  cout << endl;
  for (auto x: a.searchRange(d, 3))
    cout << x << ' ';
  cout << endl;
  for (auto x: a.searchRange(e, 1))
    cout << x << ' ';
  cout << endl;

  return 0;
}
