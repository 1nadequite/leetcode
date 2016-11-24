// 204. Count Primes
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
  int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    for (int i = 2; i * i < n; ++i) {
      if (!isPrime[i]) continue;
      for (int j = i * i; j < n; j += i)
        isPrime[j] = false;
    }
    int count = 0;
    for (int i = 2; i < n; ++i)
      if (isPrime[i]) count++;
    return count;
  }
};

int main() {
  Solution a;
  cout << a.countPrimes(14) << endl;
  cout << a.countPrimes(135) << endl;

  return 0;
}
