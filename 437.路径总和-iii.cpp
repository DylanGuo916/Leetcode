/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
  
public:
  int pathSum(TreeNode* root, int targetSum) {
    if (!root)
      return 0;
    if (root->val == targetSum)
      return 1;
    return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + pathSum(root->left, targetSum - root->val) + pathSum(root->right, targetSum - root->val);
  }
};
// @lc code=end

