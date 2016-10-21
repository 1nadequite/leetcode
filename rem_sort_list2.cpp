// 83. Remove Duplicates from Sorted List II (medium)
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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return 0;
    if (!head->next) return head;

    if (head->val != head->next->val) {
      head->next = deleteDuplicates(head->next);
      return head;
    } else {
      while (head->next && head->val == head->next->val) head->next = head->next->next;
      return deleteDuplicates(head->next);
    }
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
  ins(2, root);
  ins(3, root);
  ins(3, root);
  ins(4, root);
  ins(4, root);
  ins(5, root);
  pr(root);
  root = a.deleteDuplicates(root);
  pr(root);

  ListNode* root1 = new ListNode(1);
  ins(1, root1);
  ins(1, root1);
  ins(2, root1);
  ins(3, root1);
  pr(root1);
  root1 = a.deleteDuplicates(root1);
  pr(root1);

  return 0;
}
