// 89. Gray Code (medium)
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
  vector<int> grayCode(int n) {
    vector<int> ans;
    for (int i = 2; i < (1 << n); ++i)
      ans.push_back((i >> 1) ^ i);
    return ans;
  }
};

int main() {
  Solution a;
  for (auto x: a.grayCode(2))
    cout << x << endl;

  return 0;
}
