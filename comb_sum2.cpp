// 40. Combination Sum II (medium)
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
        if (cand[i]) {
          int num = i, cnt = cand[i], j = 0, cur_sum = comb_sum;
          while (j < cnt) {
            tmp.push_back(num);
            cur_sum += num;
            bt(cur_sum, i + 1, target, tmp, cand, ans);
            j++;
          }
          while (cnt) {
            tmp.pop_back();
            cnt--;
          }
        }
      }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidate, int target) {
      vector<vector<int>> ans;
      vector<int> tmp, cand(target + 1);
      for (int i = 0; i < candidate.size(); ++i)
        if (candidate[i] <= target)
          cand[candidate[i]]++;
      bt(0, 0, target, tmp, cand, ans);
      return ans;
    }
};

int main() {
  Solution a;
  vector<int> b = {10, 1, 2, 7, 6, 1, 5};
  vector<int> c = {2, 5, 2, 1, 2};
  vector<int> d = {1, 1, 2, 5, 6, 7, 10};
  for (auto x: a.combinationSum2(c, 5)) {
    for (auto y: x)
      cout << y << ' ';
    cout << endl;
  }

  return 0;
}
