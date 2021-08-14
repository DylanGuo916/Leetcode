/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
#include <unordered_map>
using namespace std;
class Solution {
public:
  vector<int> res;
  vector<int> rightSideView(TreeNode* root) {
    if (!root)
      return res;
    res.push_back(root->val);
    while (root->right) {
      root = root->right;
      res.push_back(root->val);
    }
  }
};
// @lc code=end

