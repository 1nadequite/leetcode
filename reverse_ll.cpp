// 206. Reverse Linked List (easy)
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
  ListNode* reverseList1(ListNode* head) {
    ListNode *prev = NULL, *tmp;
    while (head) {
      tmp = head->next;
      head->next = prev;
      prev = head;
      head = tmp;
    }
    return prev;
  }
  ListNode* reverseList(ListNode* head) {
    if (!head || !(head->next)) return head;
    auto ans = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return ans;
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
  root = a.reverseList(root);
  pr(root);

  return 0;
}
