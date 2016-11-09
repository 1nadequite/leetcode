// 102. Binary Tree Level Order Traversal (easy)
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
  void levelOrder(TreeNode *root, int lvl, vector<vector<int>>& ans) {
    if (!root) return;
    if (ans.size() > lvl) ans[lvl].push_back(root->val);
    else ans.push_back({root->val});
    levelOrder(root->left, lvl + 1, ans);
    levelOrder(root->right, lvl + 1, ans);
  }
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    levelOrder(root, 0, ans);
    return ans;
  }
};

int main() {
  Solution a;

  return 0;
}
