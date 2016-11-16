// 129. Sum Root to Leaf Numbers (medium)
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
  void dfs(TreeNode* root, int tmp, int& ans) {
    if (!root) return;
    if (!root->left && !root->right) {
      ans += tmp * 10 + root->val;
      return;
    }
    dfs(root->left, tmp * 10 + root->val, ans);
    dfs(root->right, tmp * 10 + root->val, ans);
  }
  int sumNumbers(TreeNode* root) {
    int ans = 0;
    dfs(root, 0, ans);
    return ans;
  }
};

int main() {
  Solution a;

  return 0;
}
