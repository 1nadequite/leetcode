// 168. Excel Sheet Column Title
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
  string convertToTitle(int n) {
    string s;
    while (n) {
      n--;
      int tmp = n % 26;
      char c = tmp + 'A';
      s = c + s;
      n /= 26;
    }
    return s;
  }
};

int main() {
  Solution a;
  cout << a.convertToTitle(26) << endl;
  cout << a.convertToTitle(27) << endl;
  cout << a.convertToTitle(33) << endl;
  cout << a.convertToTitle(53) << endl;

  return 0;
}
