// 86. Partition List (medium)
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
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    ListNode *lh = NULL, *lt = NULL;
    ListNode *rh = NULL, *rt = NULL;
    while (head) {
      if (head->val < x) {
        if (lt) {
          lt->next = head;
          lt = lt->next;
        } else {
          lh = lt = head;
        }
      } else {
        if (rt) {
          rt->next = head;
          rt = rt->next;
        } else {
          rh = rt = head;
        }
      }
      head = head->next;
    }
    if (rt) rt->next = NULL;
    if (lt) {
      lt->next = rh;
      return lh;
    }
    return rh;
  }
};

void ins(int x, ListNode* head) {
  ListNode* cur = head;
  while (cur->next != NULL)
    cur = cur->next;
  ListNode* n = new ListNode(x);
  cur->next = n;
}

void pr(ListNode* head) {
  ListNode* cur = head;
  while (cur != NULL) {
    cout << cur->val << ' ';
    cur = cur->next;
  }
  cout << endl;
}

int main() {
  Solution a;
  ListNode* root = new ListNode(1);
  ins(4, root);
  ins(3, root);
  ins(2, root);
  ins(5, root);
  ins(2, root);
  pr(root);
  root = a.partition(root, 3);
  pr(root);

  return 0;
}
