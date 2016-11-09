// 101. Symmetric Tree (easy)
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  bool find(TreeNode *l, TreeNode *r) {
    if (!l && !r) return 1;
    if (!l || !r || l->val != r->val) return 0;
    return (find(l->left, r->right) && find(l->right, r->left));
  }
  bool isSymmetric(TreeNode* root) {
    if (!root) return 1;
    return find(root->left, root->right);
  }
};

void ins {

int main() {
  Solution a;

  return 0;
}
