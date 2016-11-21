// 145. Binary Tree Postorder Traversal (hard)
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
  void postOrder(TreeNode* root, vector<int>& ans) {
    if (!root) return;
    postOrder(root->left, ans);
    postOrder(root->right, ans);
    ans.push_back(root->val);
  }
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    postOrder(root, ans);
    return ans;
  }
};

int main() {
  Solution a;

  return 0;
}
