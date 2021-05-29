/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
#include <vector>
using namespace std;
class Solution {
private;
  unordered_map<int, int> index;
  TreeNode *myBuildTree(vector<int> &inorder, vector<int> &postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right) {
    if (inorder_right < inorder_left)
      return nullptr;
    
    int postorder_root = postorder_right;
    int inorder_root = index[postorder[postorder_root]];
    int size_left_subtree = inorder_root - inorder_left;
    TreeNode *root = new TreeNode(postorder[postorder_root]);
    root->left = myBuildTree(inorder, postorder, inorder_left, inorder_root - 1, postorder_left, postorder_left + size_left_subtree);
    root->right = myBuildTree(inorder, postorder, inorder_root + 1, inorder_right, postorder_left + size_left_subtree + 1, postorder_right);
    return root;
  } 
public: 
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = inorder.size();
    for (int i = 0; i < n; ++i)
      index[inorder[i]] = i;
    return myBuildTree(inorder, postorder, 0, n - 1, 0, n - 1);
  }
};
// @lc code=end

