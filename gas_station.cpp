// 134. Gas Station (medium)
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
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int tank = 0, sum = 0, start = 0;
    for (int i = 0; i < n; ++i) {
      tank += gas[i] - cost[i];
      sum += tank;
      if (tank < 0) {
        tank = 0;
        start = i + 1;
      }
    }
    if (sum < 0) return -1;
    else return start;
  }
};

int main() {
  Solution a;
  vector<int> b = {3, 1, 5, 1, 2}, c = {4, 2, 1, 4, 5};
  cout << a.canCompleteCircuit(b, c) << endl;

  return 0;
}
