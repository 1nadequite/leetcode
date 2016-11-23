// 191. Number of 1 Bits
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
    int hammingWeight(uint32_t n) {
      int ans = 0;
      while (n) {
        ans += n & 1;
        n >>= 1;
      }
      return ans;
    }
};

int main() {
  Solution a;

  return 0;
}
