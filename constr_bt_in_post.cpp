// 106. Construct Binary Tree from Inorder and Postorder Traversal (medium)
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
  int search(vector<int>& inorder, int start, int end, int val) {
    int i;
    for (i = start; i <= end; ++i)
      if (inorder[i] == val) break;
      return i;
  }
  TreeNode *build(vector<int>& inorder, vector<int>& postorder, int start, int end, int& post_order) {
    if (start > end) return NULL;
    TreeNode *node = new TreeNode(postorder[post_order]);
    post_order--;
    if (start == end) return node;

    int in_order = search(inorder, start, end, node->val);
    node->right = build(inorder, postorder, in_order + 1, end, post_order);
    node->left = build(inorder, postorder, start, in_order - 1, post_order);
    return node;
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int post_order = inorder.size() - 1;
    return build(inorder, postorder, 0, inorder.size() - 1, post_order);
  }
};

int main() {
  Solution a;

  return 0;
}
