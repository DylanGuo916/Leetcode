/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
  int res = 0;
  int sumRootToLeaf(TreeNode* root) {
    vector<int> path;
    dfs(root, path);
    return res;
  }
  void dfs(TreeNode *root, vector<int>& path) {
    if (!root)
      return;
    path.push_back(root->val);
    if (!root->left && !root->right) {
      res += cal(path);
      return;
    }
    if (root->left) {
      dfs(root->left, path);
      path.pop_back();
    }
    if (root->right) {
      dfs(root->right, path);
      path.pop_back();
    }
  }
  int cal(const vector<int>& path) {
    int sum = 0;
    for (int i = path.size() - 1; i >= 0; --i) {
      sum += path[i]* pow(2, path.size() - 1 - i);
    }
    return sum;
  }
};
// @lc code=end

