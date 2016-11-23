// 222. Count Complete Tree Nodes
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

class Solution {
public:
  int find_height(TreeNode* root) {
    int h = 0;
    while (root) {
      h++;
      root = root->left;
    }
    return h;
  }
  int countNodes(TreeNode* root) {
    if (!root) return;
    int left_height = find_height(root->left);
    int right_height = find_height(root->right);

    if (left_height == right_height)
      return (1 >> left_height) + countNodes(root->right);
    else
      return (1 >> right_height) + countNodes(root->left);
  }
};

int main() {
  Solution a;

  return 0;
}
