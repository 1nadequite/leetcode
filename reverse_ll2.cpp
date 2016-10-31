// 92. Reverse Linked List II (medium)
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m == n) return head;
    ListNode *start = new ListNode(0);
    start->next = head;
    ListNode *p = start;
    int i = 1;
    while (i < m && p->next) {
      p = p->next;
      i++;
    }
    ListNode *l = p->next, *r = p->next, *prev = NULL, *tmp;
    while (i <= n && l) {
      tmp = l->next;
      l->next = prev;
      prev = l;
      l = tmp;
      i++;
    }
    r->next = tmp;
    p->next = prev;
    return start->next;
  }
};

void ins(ListNode *root, int x) {
  ListNode *cur = root;
  while (cur->next != NULL) cur = cur->next;
  ListNode *n = new ListNode(x);
  cur->next = n;
}

void pr(ListNode *root) {
  ListNode *cur = root;
  while (cur) {
    cout << cur->val << ' ';
    cur = cur->next;
  }
  cout << endl;
}

int main() {
  Solution a;
  ListNode *root = new ListNode(1);
  ins(root, 2);
  ins(root, 3);
  ins(root, 4);
  ins(root, 5);
  pr(root);
  root = a.reverseBetween(root, 2, 4);
  pr(root);

  return 0;
}
