// 98. Validate Binary Search Tree (medium)
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
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  bool isValid(TreeNode *root, TreeNode *min, TreeNode *max) {
    if (!root) return true;
    if ((min && root->val <= min->val) || (max && root->val >= max->val)) return false;
    return (isValid(root->left, min, root) && isValid(root->right, root, max));
  }
  bool isValidBST(TreeNode* root) {
    return isValid(root, NULL, NULL);
  }
};

int main() {
  Solution a;

  return 0;
}
