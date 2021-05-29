/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
#include <queue>
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) return res;
    
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    bool isOrderLeft = true;

    while (!nodeQueue.empty()) {
      int levelSize = nodeQueue.size();
      deque<int> currLevel;
      int level = 0;

      for (int i = 0; i < levelSize; ++i) {
        auto currNode = nodeQueue.front();
        nodeQueue.pop();
        if (isOrderLeft)
          currLevel.push_back(currNode->val);
        else
          currLevel.push_front(currNode->val);
        if (currNode->left)
          nodeQueue.push(currNode->left);
        if (currNode->right)
          nodeQueue.push(currNode->right);
      }
      res.emplace_back(vector<int>(currLevel.begin(), currLevel.end()));
      isOrderLeft = !isOrderLeft;
    }
    return res;
  }
};
// @lc code=end

