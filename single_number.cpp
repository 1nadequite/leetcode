// 136. Single Number (easy)
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
    for (int i = 1; i < nums.size(); ++i)
      nums[0] ^= nums[i];
    return nums[0];
  }
};

int main() {
  Solution a;
  vector<int> b = {1, 3, 1, 2, 2};
  cout << a.singleNumber(b) << endl;

  return 0;
}
