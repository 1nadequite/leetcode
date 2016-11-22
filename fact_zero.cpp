// 172. Factorial Trailing Zeroes
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
  int trailingZeroes(int n) {
    int ans = 0;
    while (n) {
      ans += n / 5;
      n /= 5;
    }
    return ans;
  }
};

int main() {
  Solution a;
  cout << a.trailingZeroes(16) << endl;
  cout << a.trailingZeroes(8) << endl;
  cout << a.trailingZeroes(1254) << endl;

  return 0;
}
