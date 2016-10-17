// 58. Length of Last Word (easy)
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
  int lengthOfLastWord(string s) {
    int n = s.size(), length = 0;
    if (n == 0) return 0;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == ' ') {
        if (length == 0) continue;
        else return length;
      } else length++;
    }
    return length;
  }
};

int main() {
  Solution a;
  string s = "Hello world";
  string t = "Hello ";
  cout << a.lengthOfLastWord(s) << endl;
  cout << a.lengthOfLastWord(t) << endl;

  return 0;
}
