// 69. Sqrt(x) (medium)
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
  int mySqrt(int x) {
    if (x == 1) return x;
    int l = 0, r = min((x >> 1) + 1, 46341);
    while (r - l > 1) {
      int mid = (l + r) >> 1;
      if (mid * mid > x) r = mid;
      else l = mid;
    }
    return l;
  }
};

int main() {
  Solution a;
  cout << a.mySqrt(2147395599) << endl;
  cout << a.mySqrt(22) << endl;
  cout << a.mySqrt(1) << endl;
  cout << a.mySqrt(2) << endl;

  return 0;
}
