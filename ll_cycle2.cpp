// 142. Linked List Cycle II (medium)
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *a = head, *b = head;
    while (a && a->next) {
      a = a->next->next;
      b = b->next;
      if (a == b) break;
    }
    if (!a || !a->next) return NULL;
    b = head;
    while (a != b) {
      a = a->next;
      b = b->next;
    }
    return a;
  }
};

int main() {
  Solution a;

  return 0;
}
