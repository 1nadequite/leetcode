// 133. Clone Graph (medium)
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
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    map<int, UndirectedGraphNode*> newUGN;
    return dfs(node, newUGN);
  }
  UndirectedGraphNode *dfs(UndirectedGraphNode *node, map<int, UndirectedGraphNode*>& newUGN) {
    if (!node) return node;
    UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
    newUGN[node->label] = new_node;
    for (auto n: node->neighbors) {
      auto it = newUGN.find(n->label);
      if (it == newUGN.end())
        new_node->neighbors.push_back(dfs(n, newUGN));
      else
        new_node->neighbors.push_back(it->second);
    }
    return new_node;
  }
};

int main() {
  Solution a;

  return 0;
}
