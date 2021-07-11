/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
  void dfs(TreeNode* root, vector<int>& inorder) {
    if (root == nullptr)
      return;
    dfs(root->left, inorder);
    inorder.push_back(root->val);
    dfs(root->right, inorder);
  }

  int getMinimumDifference(vector<int>& inorder) {
    int minDiff = abs(inorder[1] - inorder[0]);
    for (int i = 2; i < inorder.size(); ++i) {
      if (abs(inorder[i] - inorder[i-1]) < minDiff) {
        minDiff = abs(inorder[i] - inorder[i - 1]);
      }
    }
    return minDiff;
  }

  int getMinimumDifference(TreeNode* root) {
    vector<int> inorder;
    dfs(root, inorder);
    return getMinimumDifference(inorder);
  }
};
// @lc code=end

