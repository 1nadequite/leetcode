// 61. Rotate List (medium)
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
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL) return head;
    ListNode* cur = head;
    int sz = 1;
    while (cur->next != NULL) {
      cur = cur->next;
      sz++;
    }
    int rot = sz - k % sz;
    cur->next = head;
    while (rot) {
      cur = cur->next;
      rot--;
    }
    head = cur->next;
    cur->next = NULL;
    return head;
  }
};

void ins(int x, ListNode* root) {
  ListNode* cur = root;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  ListNode* n = new ListNode(x);
  cur->next = n;
}

void pr(ListNode* root) {
  ListNode* cur = root;
  while (cur != NULL) {
    cout << cur->val << "->";
    cur = cur->next;
  }
  cout << "NULL" << endl;
}

int main() {
  Solution a;
  ListNode* b = new ListNode(1);
  ins(2, b);
  ins(3, b);
  ins(4, b);
  ins(5, b);
  pr(b);
  ListNode* n = a.rotateRight(b, 6);
  pr(n);

  return 0;
}
