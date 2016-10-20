// 75. Sort Colors (medium)
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
  void sortColors(vector<int>& nums) {
    int r = 0, w = 0, b = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        nums[b++] = 2;
        nums[w++] = 1;
        nums[r++] = 0;
      }
      else if (nums[i] == 1) {
        nums[b++] = 2;
        nums[w++] = 1;
      }
      else nums[b++] = 2;
    }
  }
};

int main() {
  Solution a;
  vector<int> b = {2,1,0,0,1,2,2,2,0,0};
  a.sortColors(b);
  for (auto& x: b)
    cout << x << ' ';
  cout << endl;

  return 0;
}
