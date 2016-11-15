// 119. Pascal's Triangle II (easy)
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
  vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex + 1);
    ans[0] = 1;
    for (int i = 1; i <= rowIndex; ++i)
      for (int j = i; j > 0; --j)
        ans[j] += ans[j - 1];
    return ans;
  }
};

int main() {
  Solution a;
  for (auto& x: a.getRow(3))
    cout << x << ' ';
  cout << endl;

  return 0;
}
