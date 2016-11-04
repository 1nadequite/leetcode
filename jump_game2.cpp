// 45. Jump Game II (hard)
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
  int jump(vector<int>& nums) {
    if (nums.size() <= 1) return 0;
    int l = 0, r = 0, jump = 0, next = 0;
    while (true) {
      r = next + nums[next];
      if (r >= nums.size() - 1) break;
      int mx = 0;
      for (int i = l + 1; i <= r; ++i) {
        if (i + nums[i] > mx) {
          mx = i + nums[i];
          next = i;
        }
      }
      l = r;
      jump++;
    }
    return jump + 1;
  }
};

int main() {
  Solution a;
  vector<int> b = {2, 3, 1, 1, 4};
  vector<int> c = {4, 1, 1, 3, 1, 1, 1};
  cout << a.jump(b) << endl;
  cout << a.jump(c) << endl;

  return 0;
}
