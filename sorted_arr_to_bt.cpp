// 108. Convert Sorted Array to Binary Search Tree (medium)
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
  TreeNode *build(vector<int>& nums, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) >> 1;
    TreeNode *node = new TreeNode(nums[mid]);
    if (start == end) return node;

    node->left = build(nums, start, mid - 1);
    node->right = build(nums, mid + 1, end);
    return node;
  }
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return build(nums, 0, nums.size() - 1);
  }
};

int main() {
  Solution a;

  return 0;
}
