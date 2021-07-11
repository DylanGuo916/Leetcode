/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
class Solution {
private:
  vector<TreeNode*> helper;
  void dfs(TreeNode* root) {
    if (!root)
      return;
    helper.push_back(root);
    dfs(root->left);
    dfs(root->right);
  }
public:
  void flatten(TreeNode* root) {
    if (!root)
      return;
    dfs(root);
    for (int i  = 0; i < helper.size() - 1; ++i) {
      helper[i]->left = nullptr;
      helper[i]->right = helper[i + 1];
    }
    helper[helper.size() - 1]->left = nullptr;
    helper[helper.size() - 1]->right = nullptr;
  }
};
// @lc code=end

