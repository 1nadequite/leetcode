// 55. Jump Game (medium)
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
  // backtracking O(2^n)
  bool jump(int pos, const vector<int>& nums) {
    int n = nums.size() - 1;
    if (pos >= n) return true;
    //if (nums[pos] == 0) return false;
    int l = pos + 1, r = min((pos + nums[pos]), n);
    for (int i = l; i <= r; ++i)
      if (jump(i, nums))
        return true;
    return false;
  }
  bool canJump1(vector<int>& nums) {
    return jump(0, nums);
  }
  // dynamic programming (top-down) O(n^2)
  bool jump(int pos, vector<int>& m, const vector<int>& nums) {
    int n = nums.size() - 1;
    if (m[pos] != 0)
      return (m[pos] == 2) ? true : false;

    int l = pos + 1, r = min((pos + nums[pos]), n);
    for (int i = l; i <= r; ++i) {
      if (jump(i, m, nums)) {
        m[i] = 2;
        return true;
      }
    }
    return false;
  }
  bool canJump2(vector<int>& nums) {
    vector<int> m(nums.size(), 0);
    m[nums.size() - 1] = 2;
    return jump(0, m, nums);
  }
  // dynamic programming (bottom - up) O(n^2)
  bool canJump3(vector<int>& nums) {
    vector<int> m(nums.size(), 0);
    int n = nums.size() - 1;
    m[n] = 2;

    for (int i = n - 1; i >= 0; --i) {
      int l = i + 1, r = min((i + nums[i]), n);
      for (int j = l; j <= r; ++j) {
        if (m[j] == 2) {
          m[i] = 2;
          break;
        }
      }
    }
    return (m[0] == 2) ? true : false;
  }
  // greedy
  bool canJump(vector<int>& nums) {
    int last = nums.size() - 1, n = last;
    for (int i = n; i >= 0; --i)
      if (i + nums[i] >= last)
        last = i;
    return (last == 0) ? true : false;
  }
};

int main() {
  Solution a;
  vector<int> b = {2,3,1,1,4};
  vector<int> c = {3,2,1,0,4};
  cout << a.canJump(b) << endl;
  cout << a.canJump(c) << endl;

  return 0;
}
