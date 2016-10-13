// 39. Combination Sum (medium)
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

class Solution {
  public:
    void bt(int comb_sum, int start, int target, vector<int>& tmp, const vector<int>& cand, vector<vector<int>>& ans) {
      if (comb_sum == target) {
        ans.push_back(tmp);
        return;
      }
      if (comb_sum > target) return;
      for (int i = start; i < cand.size(); ++i) {
        if (comb_sum + cand[i] > target) continue;
        tmp.push_back(cand[i]);
        bt(comb_sum + cand[i], i, target, tmp, cand, ans);
        tmp.pop_back();
      }
    }
    vector<vector<int>> combinationSum(vector<int>& candidate, int target) {
      vector<vector<int>> ans;
      vector<int> tmp;
      bt(0, 0, target, tmp, candidate, ans);
      return ans;
    }
};

int main() {
  Solution a;
  vector<int> b = {2, 3, 6, 7};
  for (auto x: a.combinationSum(b, 7)) {
    for (auto y: x)
      cout << y << ' ';
    cout << endl;
  }

  return 0;
}
