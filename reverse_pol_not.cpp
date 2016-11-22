// 150. Evaluate Reverse Polish Notation (medium)
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

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (auto& c: tokens) {
      if (c == "+" || c == "-" || c == "/" || c == "*") {
        int y = s.top(); s.pop();
        if (c == "+") s.top() += y;
        if (c == "-") s.top() -= y;
        if (c == "/") s.top() /= y;
        if (c == "*") s.top() *= y;
      }
      else s.push(stoi(c));
    }
    return s.top();
  }
};

int main() {
  Solution a;
  vector<string> b = {"2", "1", "+", "3", "*"}, c = {"4", "13", "5", "/", "+"};
  cout << a.evalRPN(b) << endl;
  cout << a.evalRPN(c) << endl;

  return 0;
}
