// 105. Construct Binary Tree from Preorder and Inorder Traversal (medium)
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
  TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end, int& pre_index) {
    if (start > end) return NULL;
    TreeNode *node = new TreeNode(preorder[pre_index]);
    pre_index++;
    if (start == end) return node;
    int in_index = search(inorder, start, end, node->val);

    node->left = build(preorder, inorder, start, in_index - 1, pre_index);
    node->right = build(preorder, inorder, in_index + 1, end, pre_index);
    return node;
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int pre_index = 0;
    return build(preorder, inorder, 0, preorder.size() - 1, pre_index);
  }
};

int main() {
  Solution a;

  return 0;
}
