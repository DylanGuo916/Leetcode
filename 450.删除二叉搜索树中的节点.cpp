/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) return root;
    if (key > root->val) {
      root->right = deleteNode(root->right, key);
    } else if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else {
      if (root->left != nullptr && root->right != nullptr) {
        TreeNode* min = root->right;
        // 找到右子树的最小节点，与根结点交换
        while (min->left != nullptr) min = min->left;
        root->val = min->val;
        root->right = deleteNode(root->right, min->val);
      } else {
        TreeNode* new_root = root->left == nullptr ? root->right : root->left;
        root->left = root->right = nullptr;
        delete root;
        return new_root;
      }
    }
    return root;
  }
};
// @lc code=end