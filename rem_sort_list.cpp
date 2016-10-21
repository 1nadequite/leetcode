// 83. Remove Duplicates from Sorted List (easy)
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
    if (head == NULL) return head;
    ListNode* cur = head;
    while (cur->next != NULL) {
      if (cur->val == cur->next->val)
        cur->next = cur->next->next;
      else
        cur = cur->next;
    }
    return head;
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
  ins(1, root);
  ins(2, root);
  ins(2, root);
  ins(3, root);
  pr(root);
  root = a.deleteDuplicates(root);
  pr(root);

  return 0;
}
