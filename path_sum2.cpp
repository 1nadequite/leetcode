// 113. Path Sum II (medium)
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
  void find(TreeNode *root, int sum, vector<int> tmp, vector<vector<int>>& ans) {
    if (!root) return;
    sum -= root->val;
    tmp.push_back(root->val);
    if (!root->left && !root->right && sum == 0) {
      ans.push_back(tmp);
        return;
      }
    find(root->left, sum, tmp, ans);
    find(root->right, sum, tmp, ans);
  }
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    vector<int> tmp;
    find(root, sum, tmp, ans);
    return ans;
  }
};

int main() {
  Solution a;

  return 0;
}
