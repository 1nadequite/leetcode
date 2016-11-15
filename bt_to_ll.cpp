// 114. Flatten Binary Tree to Linked List (medium)
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
  void preOrder(TreeNode* root, TreeNode* &prev) {
    if (!root) return;
    TreeNode* tmp = root->right;
    prev->right = root;
    prev = root;
    preOrder(root->left, prev);
    root->left = NULL;
    preOrder(tmp, prev);
  }
  void flatten(TreeNode* root) {
    if (!root) return;
    TreeNode* tmp = root->right, *prev = root;
    preOrder(root->left, prev);
    root->left = NULL;
    preOrder(tmp, prev);
  }
};

int main() {
  Solution a;

  return 0;
}
