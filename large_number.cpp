// 179. Largest Number
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
  static bool compare(const int& a, const int& b) {
    return (to_string(a) + to_string(b) > to_string(b) + to_string(a));
  }
  string largestNumber(vector<int>& nums) {
    string s;
    sort(nums.begin(), nums.end(), compare);
    for (auto& x: nums) s += to_string(x);
    while (s.size() > 1 && s[0] == '0' && s[1] == '0')
      s.erase(s.begin());
    return s;
  }
};

int main() {
  Solution a;
  vector<int> b = {3, 30, 34, 5, 9};
  cout << a.largestNumber(b) << endl;

  return 0;
}
