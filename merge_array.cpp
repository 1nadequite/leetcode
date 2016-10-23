// 88. Merge Sorted Array (easy)
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
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
      if (nums1[i] > nums2[j]) {
        nums1[k] = nums1[i];
        i--; k--;
      } else {
        nums1[k] = nums2[j];
        j--; k--;
      }
    }
    while (i >= 0) {
      nums1[k] = nums1[i];
      i--; k--;
    }
    while (j >= 0) {
      nums1[k] = nums2[j];
      j--; k--;
    }
  }
};

int main() {
  Solution a;
  vector<int> b = {1, 4, 5, 6, 0, 0, 0, 0}, c = {2, 3, 5, 7};
  a.merge(b, 4, c, 4);
  for (auto& x: b)
    cout << x << ' ';
  cout << endl;

  return 0;
}
