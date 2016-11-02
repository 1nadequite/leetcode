// 100. Same Tree (easy)
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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    else if (!p || !q || p->val != q->val) return false;
    else return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
  }
};

int main() {
  Solution a;

  return 0;
}
