// 121. Best Time to Buy and Sell Stock (easy)
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
    int profit = 0, mn = 1e9, n = prices.size();
    for (int i = 0; i < n; ++i) {
      mn = min(mn, prices[i]);
      profit = max(profit, prices[i] - mn);
    }
    return profit;
  }
};

int main() {
  Solution a;
  vector<int> b = {7, 1, 5, 3, 6, 4}, c = {7, 6, 4, 3, 1};
  cout << a.maxProfit(b) << endl;
  cout << a.maxProfit(c) << endl;

  return 0;
}
