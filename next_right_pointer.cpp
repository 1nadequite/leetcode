// 116. Populating Next Right Pointers in Each Node (medium)
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
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (!root) return;
    if (root->left) root->left->next = root->right;
    if (root->next && root->next->left) root->right->next = root->next->left;
    connect(root->left);
    connect(root->right);
  }
};

int main() {
  Solution a;

  return 0;
}
