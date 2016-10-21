// 80. Remove Duplicates from Sorted Array II (medium)
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
  int removeDuplicates1(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int i = 1;
    while (i < nums.size()) {
      if (nums[i] == nums[i - 1]) i++;
      while (nums[i] == nums[i - 1] && i < nums.size()) nums.erase(nums.begin() + i);
      i++;
    }
    return nums.size();;
  }
  int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (auto& x: nums)
      if (i < 2 || x > nums[i - 2])
        nums[i++] = x;
    return i;
  }
};

int main() {
  Solution a;
  vector<int> b = {1, 1, 1, 2, 2, 3};
  vector<int> c = {1, 1, 1, 2, 2, 3, 3};
  vector<int> d = {1, 2, 2, 3, 3, 3};
  cout << a.removeDuplicates(b) << endl;
  cout << a.removeDuplicates(c) << endl;
  cout << a.removeDuplicates(d) << endl;

  return 0;
}
