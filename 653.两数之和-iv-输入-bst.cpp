/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> set;
    return find(root, k, set);
  }

  bool find(TreeNode *root, int k, unordered_set<int>& set) {
    if (root == nullptr)
      return false;
    if (set.find(k - root->val) != set.end())
      return true;
    set.insert(root->val);
    return find(root->left, k, set) || find(root->right, k, set);
  }
};
// @lc code=end

