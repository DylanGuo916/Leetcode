/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    if (!root)
      return;
    dfs(root->left, inorder);
    inorder.push_back(root->val);
    dfs(root->right, inorder);
  }

  int minDiffInBST(TreeNode* root) {
    vector<int> inorder;
    dfs(root, inorder);
    int min = inorder[1] - inorder[0];
    for (int i = 2; i < inorder.size(); ++i) {
      if (inorder[i] - inorder[i - 1] < min)
        min = inorder[i] - inorder[i - 1];
    }
    return min;
  }
};
// @lc code=end

