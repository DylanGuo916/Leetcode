/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
  int x;
  TreeNode* x_parent;
  int x_depth;
  bool x_found = false;
  int y;
  TreeNode* y_parent;
  int y_depth;
  bool y_found = false;
public:
  void dfs(TreeNode* node, int depth, TreeNode* parent) {
    if (!node)
      return;
    if (node->val == x) {
      x_parent = parent;
      x_depth = depth;
      x_found = true;
    } else if (node->val == y) {
      y_parent = parent;
      y_depth = depth;
      y_found = true;
    }
    //找到两个节点退出递归
    if (x_found && y_found)
      return; 
    //在左子树里找
    dfs(node->left, depth + 1, node);
    //找到两个节点退出递归
    if (x_found && y_found)
      return; 
    //在右子树里找
    dfs(node->right, depth + 1, node);
  }
  bool isCousins(TreeNode* root, int x, int y) {
    this->x = x;
    this->y = y;
    dfs(root, 0, nullptr);
    //堂兄弟节点条件，深度相同 & 父节点不同
    return x_depth == y_depth && x_parent != y_parent;
  }
};
// @lc code=end

