// 125. Valid Palindrome (easy)
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
  bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      while (s[l] < '0' || (s[l] > '9' && s[l] < 'A') || (s[l] > 'Z' && s[l] < 'a') || s[l] > 'z') l++;
      while (s[r] < '0' || (s[r] > '9' && s[r] < 'A') || (s[r] > 'Z' && s[r] < 'a') || s[r] > 'z') r--;
      if (l >= r) break;
      if (tolower(s[l]) != tolower(s[r])) return false;
      l++; r--;
    }
    return true;
  }
};

int main() {
  Solution a;
  cout << a.isPalindrome("A man, a plan, a canal: Panama") << endl;
  cout << a.isPalindrome("race a car") << endl;

  return 0;
}
