/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
  void dfs(TreeNode* root, vector<TreeNode*>& inorder) {
    if (!root)
      return;
    dfs(root->left, inorder);
    inorder.push_back(root);
    dfs(root->right, inorder);
  }
  TreeNode* increasingBST(TreeNode* root) {
    vector<TreeNode*> inorder;
    dfs(root, inorder);
    TreeNode* sentinel = nullptr;
    inorder.push_back(sentinel);
    for (int i = 0; i < inorder.size() - 1; ++i) {
      inorder[i]->left = nullptr;
      inorder[i]->right = inorder[i + 1];
    }
    return inorder[0];
  }
};
// @lc code=end

