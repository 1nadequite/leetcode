// 144. Binary Tree Preorder Traversal (medium)
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
  void preOrder(TreeNode* root, vector<int>& ans) {
    if (!root) return;
    ans.push_back(root->val);
    preOrder(root->left, ans);
    preOrder(root->right, ans);
  }
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    preOrder(root, ans);
    return ans;
  }
};

int main() {
  Solution a;

  return 0;
}
