/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
  void getLeavesValue(TreeNode* root, vector<int>& leavesValue) {
    if (!root)
      return;
    if (!root->left && !root->right)
      leavesValue.push_back(root->val);
    getLeavesValue(root->left, leavesValue);
    getLeavesValue(root->right, leavesValue);
  }
  int findSecondMinimumValue(TreeNode* root) {
    if (!root)
      return -1;
    vector<int> leavesValue;
    getLeavesValue(root, leavesValue);
    sort(leavesValue.begin(), leavesValue.end());
    for (int i = 1; i < leavesValue.size(); ++i) {
      if (leavesValue[i] != leavesValue[i - 1])
        return leavesValue[i];
    }
    return -1;
  }
};
// @lc code=end

