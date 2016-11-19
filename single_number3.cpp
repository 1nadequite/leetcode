// Given an array of integers, where each element has a pair, except of two. Find these two elements.
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

class Solution {
public:
  void twoNumbers(vector<int>& nums) {
    int n = nums.size();
    int tmp = 0;
    for (int i = 0; i < n; ++i)
      tmp ^= nums[i];
    int mask = 1;
    while ((tmp & mask) == 0)
      mask <<= 1;
    int fn = 0, sn = 0;
    for (int i = 0; i < n; ++i) {
      if ((mask & nums[i]) == 0) fn ^= nums[i];
      else sn ^= nums[i];
    }
    cout << fn << ' ' << sn << endl;
  }
};

int main() {
  Solution a;
  vector<int> b = {1, 2, 3, 2, 4, 3}, c = {1, 2, 3, 4, 3, 4}, d = {1, 2, 2, 1, 4, 3}, e = {234, 11, 16, 112, 16, 234};
  a.twoNumbers(b);
  a.twoNumbers(c);
  a.twoNumbers(d);
  a.twoNumbers(e);

  return 0;
}
