// 56. Merge Intervals (hard)
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

struct Interval {
  int start;
  int end;
  Interval(int s, int e): start(s), end(e) {}
};

void pr(vector<Interval>& a);

class Solution {
public:
  static bool mycomp(const Interval& a, const Interval& b) {
    return a.start < b.start;
  }
  vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.size() == 0) return intervals;
    sort(intervals.begin(), intervals.end(), mycomp);
    vector<Interval> ans;
    ans.push_back(intervals[0]);
    int i = 0, j = 1;
    while (j < intervals.size()) {
      if (ans[i].end >= intervals[j].start) {
        ans[i].start = min(ans[i].start, intervals[j].start);
        ans[i].end = max(ans[i].end, intervals[j].end);
        j++;
      } else {
        ans.push_back(intervals[j]);
        i++; j++;
      }
    }
    return ans;
  }
};

void ins(vector<Interval>& a, int s, int e) {
  a.push_back(Interval(s, e));
}

void pr(vector<Interval>& a) {
  for (auto x: a)
    cout << '[' << x.start << ',' << x.end << ']' << ' ';
  cout << endl;
}

int main() {
  Solution a;
  vector<Interval> b;
  ins(b, 1, 3);
  ins(b, 2, 6);
  ins(b, 8, 10);
  ins(b, 15, 18);
  pr(b);
  vector<Interval> c = a.merge(b);
  pr(c);

  return 0;
}
