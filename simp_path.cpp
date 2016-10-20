// 71. Simplify Path (medium)
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
  string simplifyPath(string path) {
    string ans, tmp;
    vector<string> sp;
    int n = path.size(), i = 0;
    while (i < n) {
      int j = i + 1;
      while (path[j] != '/' && j < n) j++;
      tmp = path.substr(i + 1, j - i - 1);
      i = j;

      if (tmp == "" || tmp == ".") continue;
      if (tmp == ".." && !sp.empty()) sp.pop_back();
      else if (tmp != "..") sp.push_back(tmp);
    }
    for (auto& x: sp) ans += "/" + x;
    return ans.empty() ? "/" : ans;
  }
};

int main() {
  Solution a;
  cout << a.simplifyPath("/home/") << endl;
  cout << a.simplifyPath("/a/./b/../../c/") << endl;
  cout << a.simplifyPath("/../") << endl;
  cout << a.simplifyPath("/home//foo/") << endl;

  return 0;
}
