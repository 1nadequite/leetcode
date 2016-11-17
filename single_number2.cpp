// 137. Single Number II (medium)
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
  int singleNumber(vector<int>& nums) {
    int n = nums.size();
    vector<int> b(32);
    for (int i = 0; i < n; ++i) {
      int tmp = nums[i];
      for (int j = 31; j >= 0; --j) {
        b[j] += tmp & 1;
        tmp >>= 1;
        if (!tmp) break;
      }
    }
    int ans = 0;
    for (int i = 31; i >= 0; --i) {
      int tmp = b[i] % 3;
      if (tmp) ans += 1 << (31 - i);
    }
    return ans;
  }
};

int main() {
  Solution a;
  vector<int> b = {1, 3, 2, 1, 2, 2, 1};
  cout << a.singleNumber(b) << endl;

  return 0;
}
