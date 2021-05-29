/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
  int depthOfTree(TreeNode* root) {
    if (!root) 
      return 0;
    return max(depthOfTree(root->left), depthOfTree(root->right)) + 1;
  }
public:
    int diameterOfBinaryTree(TreeNode* root) {
      if (!root)
        return 0;
      int tempDiameter = depthOfTree(root->left) + depthOfTree(root->right);
      int leftDiameter = diameterOfBinaryTree(root->left);
      int rightDiameter = diameterOfBinaryTree(root->right);
      return max(tempDiameter, max(leftDiameter, rightDiameter));
    }
};
// @lc code=end

