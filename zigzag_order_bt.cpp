// 103. Binary Tree Zigzag Level Order Traversal (medium)
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
  // using stack
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    stack<TreeNode*> toright, toleft;
    TreeNode *node = root;
    toright.push(node);
    bool left_right = true;
    while (!toright.empty() || !toleft.empty()) {
      vector<int> tmp;
      if (left_right) {
        int n = toright.size();
        for (int i = 0; i < n; ++i) {
          node = toright.top();
          toright.pop();
          tmp.push_back(node->val);
          if (node->left) toleft.push(node->left);
          if (node->right) toleft.push(node->right);
        }
      } else {
        int n = toleft.size();
        for (int i = 0; i < n; ++i) {
          node = toleft.top();
          toleft.pop();
          tmp.push_back(node->val);
          if (node->right) toright.push(node->right);
          if (node->left) toright.push(node->left);
        }
      }
      ans.push_back(tmp);
      left_right = !left_right;
    }
    return ans;
  }
  // dfs
  void levelOrder(TreeNode *root, int lvl, vector<vector<int>>& ans) {
    if (!root) return;
    if (ans.size() > lvl) ans[lvl].push_back(root->val);
    else ans.push_back({root->val});
    levelOrder(root->left, lvl + 1, ans);
    levelOrder(root->right, lvl + 1, ans);
  }
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    levelOrder(root, 0, ans);
    for (int i = 1; i < ans.size(); i += 2)
        reverse(ans[i].begin(), ans[i].end());
    return ans;
  }
};


int main() {
  Solution a;

  return 0;
}
