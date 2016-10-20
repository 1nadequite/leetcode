// 67. Add Binary (easy)
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
  string addBinary(string a, string b) {
    int an = a.size() - 1, bn = b.size() - 1;
    char cur = '0';
    string ans;
    while (an >= 0 && bn >= 0) {
      if (a[an] == b[bn]) {
        if (cur == '1') ans.push_back('1');
        else ans.push_back('0');
        if (a[an] == '1') cur = '1';
        else cur = '0';
      } else {
        if (cur == '1') {
          ans.push_back('0');
          cur = '1';
        } else {
          ans.push_back('1');
          cur = '0';
        }
      }
        an--; bn--;
    }
    while (an >= 0) {
      if (a[an] == cur) {
        if (a[an] == '1') cur = '1';
        else cur = '0';
        ans.push_back('0');
      } else {
        ans.push_back('1');
        cur = '0';
      }
      an--;
    }
    while (bn >= 0) {
      if (b[bn] == cur) {
        if (b[bn] == '1') cur = '1';
        else cur = '0';
        ans.push_back('0');
      } else {
        ans.push_back('1');
        cur = '0';
      }
      bn--;
    }

    if (cur == '1') ans.push_back('1');
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  Solution a;
  cout << a.addBinary("11", "1") << endl;
  cout << a.addBinary("1111", "1111") << endl;
  cout << a.addBinary("100", "110010") << endl;

  return 0;
}
