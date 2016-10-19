// 66. Plus One (easy)
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
  vector<int> plusOne(vector<int>& digits) {
    int n = digits.size(), cur = 1;
    for (int i = n - 1; i >= 0; --i) {
      cur += digits[i];
      digits[i] = cur % 10;
      cur /= 10;
    }
    if (cur) digits.insert(digits.begin(), cur);
    return digits;
  }
};

int main() {
  Solution a;
  vector<int> b = {9, 9, 9};
  for (auto& x : a.plusOne(b))
    cout << x;
  cout << endl;

  return 0;
}
