// 49. Group Anagrams (medium)
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
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,101};
    vector<vector<string>> ans;
    map<int, int> hash;
    int pos = 0;
    for (int i = 0; i < strs.size(); ++i) {
      int key = 1;
      for (int j = 0; j < strs[i].size(); ++j)
        key *= primes[strs[i][j] - 'a'];
      if (hash.count(key)) ans[hash[key]].push_back(strs[i]);
      else {
        hash[key] = pos;
        ans.push_back({strs[i]});
        pos++;
      }
    }
    return ans;
  }
};

int main() {
  Solution a;
  vector<string> b = {"eat", "tea", "tan", "ate", "nat", "bat"};
  for (auto& x : a.groupAnagrams(b)) {
    for (auto& y: x) {
      cout << y << ' ';
    }
    cout << endl;
  }

  return 0;
}
