// 190. Reverse Bits
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
  uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0, mx = INT_MAX + 1;
    while (n) {
      ans += (n & 1) * mx;
      n >>= 1;
      mx >>= 1;
    }
    return ans;
  }
};

int main() {
  Solution a;
  cout << a.reverseBits(43261596) << endl;
  cout << a.reverseBits(1) << endl;

  return 0;
}
