// 223. Rectangle Area
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
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int s = (C - A) * (D - B) + (G - E) * (H - F);
    if(A >= G || E >= C || B >= H || F >= D) return s;
    vector<int> h = {A, C, E, G}, v = {B, D, F, H};
    sort(h.begin(), h.end());
    sort(v.begin(), v.end());
    return s - (h[2] - h[1]) * (v[2] - v[1]);
  }
};

int main() {
  Solution a;
  cout << a.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;

  return 0;
}
