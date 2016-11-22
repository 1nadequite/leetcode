// 155. Min Stack
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

// linked list
struct Node {
  int val;
  Node *next;
  Node(int x) : val(x), next(NULL) {}
};
class MinStack {
public:
  Node *head;
  int min_val;
  MinStack() {
    head = nullptr;
    min_val = INT_MAX;
  }

  void push(int x) {
    Node *new_node = new Node(x);
    new_node->next = head;
    head = new_node;
    min_val = min(min_val, x);
  }

  void pop() {
    Node *node_to_remove = head;
    head = head->next;
    if (min_val == node_to_remove->val) {
      int min_tmp = INT_MAX;
      Node *cur = head;
      while (cur) {
        min_tmp = min(min_tmp, cur->val);
        cur = cur->next;
      }
      min_val = min_tmp;
    }
    delete(node_to_remove);
  }

  int top() {
    if (head) return tail->val;
    else return 0;
  }

  int getMin() {
    return min_val;
  }
};

int main() {
  Minstack a;

  return 0;
}
