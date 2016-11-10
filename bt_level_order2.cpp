// 107. Binary Tree Level Order Traversal II (easy)
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
  int maxHeight(TreeNode *root) {
    if (!root) return 0;
    return max(maxHeight(root->left), maxHeight(root->right)) + 1;
  }
  void levelOrder(TreeNode *root, int lvl, vector<vector<int>>& ans) {
    if (!root) return;
    ans[lvl].push_back(root->val);
    levelOrder(root->left, lvl - 1, ans);
    levelOrder(root->right, lvl - 1, ans);
  }
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int n = maxHeight(root);
    vector<vector<int>> ans(n);
    levelOrder(root, n - 1, ans);
    return ans;
  }
};

int main() {
  Solution a;

  return 0;
}
