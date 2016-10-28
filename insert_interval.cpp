// 57. Insert Interval (hard)
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
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    if (intervals.size() == 0) {
      intervals.push_back(newInterval);
      return intervals;
    }
    int l = 0, r = -1;
    for (int i = 0; i < intervals.size(); ++i) {
      int x1 = intervals[i].start, y1 = intervals[i].end;
      int x2 = newInterval.start, y2 = newInterval.end;
      if (x2 >= x1) l = i;
      if (x2 > y1) l = i + 1;
      if (y2 >= x1) r = i;
      if (y2 > y1) r = i;
    }
    if (l > r || r == -1) {
      intervals.insert(intervals.begin() + l, newInterval);
    } else {
      intervals[l].start = min(intervals[l].start, newInterval.start);
      intervals[l].end = max(intervals[r].end, newInterval.end);
      intervals.erase(intervals.begin() + l + 1, intervals.begin() + r + 1);
    }
    return intervals;
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
  ins(b, 1, 5);
  //ins(b, 6, 7);
  //ins(b, 8, 9);
  //ins(b, 12, 16);
  pr(b);
  vector<Interval> c = a.insert(b, Interval(0, 0));
  pr(c);

  return 0;
}
