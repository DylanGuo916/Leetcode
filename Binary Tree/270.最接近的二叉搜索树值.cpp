/*
 * @lc app=leetcode.cn id=270 lang=cpp
 *
 * [270] 最接近的二叉搜索树值
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int closestValue(TreeNode *root, double target) {
    int closest = root->val;
    while (root != nullptr) {
      if (abs(root->val - target) < abs(closest - target))
        closest = root->val;
      root = root->val < target ? root->right : root->left;
    }
    return closest;
  }
};
// @lc code=end
