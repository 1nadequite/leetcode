// 35. Search Insert Position
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

class Solution {
  public:
    int searchInsert(vector<int>& nums, int target) {
      int l = 0, r = nums.size();
      while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] >= target) r = mid;
        else l = mid + 1;
      }
      return l;
    }
};

int main() {
  Solution a;
  vector<int> b = {1, 3, 5, 6};
  vector<int> c = {2, 3, 4};
  vector<int> d = {1};
  cout << a.searchInsert(b, 2) << endl;
  cout << a.searchInsert(b, 3) << endl;
  cout << a.searchInsert(c, 1) << endl;
  cout << a.searchInsert(c, 5) << endl;
  cout << a.searchInsert(d, 0) << endl;

  return 0;
}
