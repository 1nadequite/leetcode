// 155. Min Stack constant time
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;
typedef long long ll;

class MinStack {
public:
  stack<int> elements;
  stack<int> min_elem;
  MinStack() {}

  void push(int x) {
    elements.push(x);
    if (min_elem.empty() || x <= min_elem.top())
      min_elem.push(x);
  }

  void pop() {
    if (elements.top() == min_elem.top())
      min_elem.pop();
    elements.pop();
  }

  int top() {
    if (elements.empty()) return 0;
    else return elements.top();
  }

  int getMin() {
    if (min_elem.empty()) return 0;
    else return min_elem.top();
  }
};

int main() {
  Minstack a;

  return 0;
}
