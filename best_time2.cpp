// 122. Best Time to Buy and Sell Stock II (medium)
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
    if (n == 0) return 0;
    int profit = 0, buy = prices[0];
    for (int i = 1; i < n; ++i) {
      int tmp = prices[i] - buy;
      while (prices[i] - buy > tmp && i < n) {
        tmp = prices[i] - buy;
        i++;
      }
      if (tmp > 0) profit += tmp;
      buy = prices[i];
    }
    return profit;
  }
};

int main() {
  Solution a;
  vector<int> b = {6, 1, 3, 2, 4, 7};
  cout << a.maxProfit(b) << endl;

  return 0;
}
