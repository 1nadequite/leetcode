// 43. Multiply Strings
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
  void add(int pos, char a, char b, string& s) {
    int x = a - '0', y = b - '0';
    x *= y;
    while (x) {
      x += (s[pos] - '0');
      s[pos--] = (x % 10) + '0';
      x /= 10;
    }
  }
  string multiply(string num1, string num2) {
    int n = num1.size(), m = num2.size();
    string s(n + m, '0');
    for (int i = n - 1; i >= 0; --i)
      for (int j = m - 1; j >= 0; --j)
        add(i + j + 1, num1[i], num2[j], s);
    int del = 0;
    while (s[del] == '0' && del < n + m - 1) del++;
    s = {s.begin() + del, s.end()};
    return s;
  }
};

int main() {
  Solution a;
  cout << a.multiply("999999999999", "0") << endl;
  cout << a.multiply("444", "444") << endl;
  cout << a.multiply("123", "321") << endl;

  return 0;
}
