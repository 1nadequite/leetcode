// 111. Minimum Depth of Binary Tree
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
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (!root->left || !root->right)
      return max(minDepth(root->left), minDepth(root->right)) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
  }
};

int main() {
  Solution a;

  return 0;
}
