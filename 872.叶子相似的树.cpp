/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
  void getLeavesSerial(TreeNode* root, vector<int>& leaves) {
    if (!root)
      return;
    if (!root->left && !root->right)
      leaves.push_back(root->val);
    getLeavesSerial(root->left, leaves);
    getLeavesSerial(root->right, leaves);
  }
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaves1;
    vector<int> leaves2;
    getLeavesSerial(root1, leaves1);
    getLeavesSerial(root2, leaves2);
    if (leaves1 == leaves2)
      return true;
    return false;
  }
};
// @lc code=end

