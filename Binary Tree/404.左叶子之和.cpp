/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
  void sumOfLeftLeaves(TreeNode* root, int& sum) {
    if (root == nullptr)
      return;
    if (root->left != nullptr) {
      TreeNode *leftTree = root->left;
      if (leftTree->left == nullptr && leftTree->right == nullptr)
        sum += leftTree->val;
    }
    sumOfLeftLeaves(root->left, sum);
    sumOfLeftLeaves(root->right, sum);  
  }
  int sumOfLeftLeaves(TreeNode* root) {
    int sum = 0;
    sumOfLeftLeaves(root, sum);
    return sum;
  }
};
// @lc code=end