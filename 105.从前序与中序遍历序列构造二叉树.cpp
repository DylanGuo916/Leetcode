/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
private:
  unordered_map<int, int> index;

  TreeNode* myBuildtree(const vector<int> & preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
    if (preorder_left > preorder_right)
      return nullptr;

    int preorder_root = preorder_left;
    int inorder_root = index[preorder[preorder_root]];
    TreeNode *root = new TreeNode(preorder[preorder_root]);

    int size_left_subtree = inorder_root - inorder_left;
    root->left = myBuildtree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
    root->right = myBuildtree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
    return root;
  }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int n = preorder.size();
      for (int i = 0; i < n; ++i) {
        index[inorder[i]] = i;
      }
      return myBuildtree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
// @lc code=end

