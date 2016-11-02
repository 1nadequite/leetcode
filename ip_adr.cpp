// 93. Restore IP Addresses (medium)
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
  vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    int n = s.size();
    if (n < 4) return ans;
    for (int i = 1; i <= 3 && i < n; ++i) {
      if (n - i > 9) continue;
      for (int j = 1; j <= 3 && i + j < n; ++j) {
        if (n - i - j > 6) continue;
        for (int k = 1; k <= 3 && i + j + k < n; ++k) {
          if (n - i - j - k > 3) continue;
          string a = s.substr(0, i);
          string b = s.substr(i, j);
          string c = s.substr(i + j, k);
          string d = s.substr(i + j + k, n);
          if (stoi(a) <= 255 && stoi(b) <= 255 && stoi(c) <= 255 && stoi(d) <= 255 &&
              (a.size() == 1 || a[0] != '0') &&
              (b.size() == 1 || b[0] != '0') &&
              (c.size() == 1 || c[0] != '0') &&
              (d.size() == 1 || d[0] != '0')) {
            string tmp = a + '.' + b + '.' + c + '.' + d;
            ans.push_back(tmp);
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution a;
  for (auto& x: a.restoreIpAddresses("25525511135")) {
    cout << x << endl;
  }

  return 0;
}
