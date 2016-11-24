// 236. Lowest Common Ancestor of a Binary Tree
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root = p || root = q) return root;
    TreeNode *p1 = lowestCommonAncestor(root->left, p, q);
    TreeNode *p2 = lowestCommonAncestor(root->right, p, q);
    if (p1 == p2) return root;
    return p1 ? p1 : p2;
  }
};

int main() {
  Solution a;

  return 0;
}
