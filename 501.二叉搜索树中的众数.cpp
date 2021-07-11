/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
  vector<int> inorder;

  void travel(TreeNode* root, vector<int>& inorder) {
    if (root == nullptr)
      return;
    travel(root->left, inorder);
    inorder.push_back(root->val);
    travel(root->right, inorder);
  }

  vector<int> findMode(TreeNode* root) {
    vector<int> res;
    if (root == nullptr)
      return res;
    travel(root, inorder);
    
    return res;
  }
};

// @lc code=end

