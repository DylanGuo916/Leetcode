/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
public:
  int tilt = 0;
  int getSum(TreeNode* root) {
    if (root == nullptr)
      return 0;
    int leftSum = getSum(root->left);
    int rightSum = getSum(root->right);
    tilt += abs(leftSum - rightSum);
    return leftSum + rightSum + root->val;
  }

  int findTilt(TreeNode* root) {
    getSum(root);
    return tilt;
  }
};
// @lc code=end

