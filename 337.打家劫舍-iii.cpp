/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>
#include <unordered_map>
using namespace std;
//dfs 动态规划
class Solution {
private:
  //维护两个哈希表，选择node时node可以向上提供的最大贡献以及不选择时
  unordered_map<TreeNode*, int> selected, unselected;

  void dfs(TreeNode* node) {
    if (!node)
      return;
    dfs(node->left);
    dfs(node->right);
    selected[node] = node->val + unselected[node->left] + unselected[node->right];
    unselected[node] = max(selected[node->left], unselected[node->left]) + max(selected[node->right], unselected[node->right]);
  }
public:
  int rob(TreeNode* root) {
    dfs(root);
    return max(selected[root], unselected[root]);
  }
};
// @lc code=end

