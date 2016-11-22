// 147. Insertion Sort List (medium)
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
  ListNode* insertionSortList(ListNode* head) {
    ListNode *ans = new ListNode(-1);
    ListNode *cur, *next;
    while (head) {
      next = head->next;
      cur = ans;
      while (cur->next && cur->next->val <= head->val)
        cur = cur->next;
      head->next = cur->next;
      cur->next = head;
      head = next;
    }
    return ans->next;
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
  ListNode* root = new ListNode(3);
  ins(1, root);
  ins(2, root);
  ins(4, root);
  ins(5, root);
  pr(root);
  root = a.insertionSortList(root);
  pr(root);

  return 0;
}
