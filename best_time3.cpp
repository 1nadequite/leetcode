// 123. Best Time to Buy and Sell Stock III (hard)
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
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return 0;
    vector<int> left(n), right(n);
    int mn = prices[0], mx = prices[n - 1];
    for (int i = 1; i < n; ++i) {
      mn = min(mn, prices[i]);
      left[i] = max(left[i - 1], prices[i] - mn);
      mx = max(mx, prices[n - 1 - i]);
      right[n - 1 - i] = max(right[n - i], mx - prices[n - 1 - i]);
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
      ans = max(ans, left[i] + right[i + 1]);
    ans = max(ans, left[n - 1]);
    return ans;
  }
};

int main() {
  Solution a;
  vector<int> b = {5,4,6,3,4,2,1,6};
  cout << a.maxProfit(b) << endl;

  return 0;
}
