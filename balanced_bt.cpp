// 110. Balanced Binary Tree (easy)
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
  int dfs(TreeNode* root) {
    if (!root) return 1;

    int left = dfs(root->left);
    if (left == 0) return 0;
    int right = dfs(root->right);
    if (right == 0) return 0;

    if (abs(left - right) > 1) return 0;
    return max(left, right) + 1;
  }
  bool isBalanced(TreeNode* root) {
    return dfs(root) == 0 ? false : true;
  }
};

int main() {
  Solution a;

  return 0;
}
