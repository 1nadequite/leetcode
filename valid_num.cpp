// 65. Valid Number (hard)
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
  bool isNumber(string s) {
    int l = 0, r = s.size() - 1;
    while (s[l] == ' ' && l < s.size()) l++;
    while (s[r] == ' ' && r >= 0) r--;
    if (l > r) return false;
    bool cnt = false;
    if (s[l] == '+' || s[l] == '-') {
      l++;
      if (l > r)  return false;
    }
    while (l <= r && isdigit(s[l])) {
      l++;
      cnt = true;
    }
    if (l > r) return true;
    if (s[l] == '.') {
      l++;
      if (!cnt && l > r) return false;
    }
    while (l <= r && isdigit(s[l])) {
      l++;
      cnt = true;
    }
    if (l > r) return true;
    if (s[l] == 'e') {
      if (!cnt) return false;
      l++;
      if (l <= r && (s[l] == '+' || s[l] == '-')) l++;
      if (l > r) return false;
      while (l <= r && isdigit(s[l])) l++;
      if (l > r) return true;
      else return false;
    }
    return false;
  }
};

int main() {
  Solution a;
  cout << a.isNumber("32.e-80123") << endl;
  //cout << a.isNumber(" 0.1") << endl;
  //cout << a.isNumber("abc") << endl;
  //cout << a.isNumber("1 a") << endl;
  //cout << a.isNumber("2e10") << endl;
  //cout << a.isNumber("+1") << endl;
  //cout << a.isNumber("+-2") << endl;

  return 0;
}

