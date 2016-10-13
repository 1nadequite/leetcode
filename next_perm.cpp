// 31. Next Permutation (medium)
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
  void nextPermutation(vector<int>& nums) {
    if (nums.size() < 2) return;
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;
    int j = nums.size() - 1;
    if (i >= 0) {
      while (j >= 0 && nums[i] >= nums[j]) j++;
      swap(nums[i], nums[j - 1]);
    }
    i = i + 1, j = nums.size() - 1;
    while (i < j) {
      swap(nums[i], nums[j]);
      i++;
      j--;
    }
  }
};

int main() {
  Solution a;
  vector<int> b = {1, 2, 3};
  vector<int> c = {3, 2, 1};
  vector<int> d = {1, 1};
  a.nextPermutation(d);
  for (auto x: d)
    cout << x << ' ';
  cout << endl;

  return 0;
}
