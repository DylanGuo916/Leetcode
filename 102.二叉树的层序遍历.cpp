/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include <vector>
#include <queue>
using namespace std;
//BFS
// class Solution {
// public:
//     vector<vector<int> > levelOrder(TreeNode* root) {
//         vector<vector<int> > res;
//         if (root == nullptr)
//             return res;

//         queue<TreeNode*> myQueue;
//         myQueue.push(root);

//         while(!myQueue.empty()){
//             int levelSize = myQueue.size(); 
//             vector<int> currLevel;

//             for (int i = 0; i < levelSize; ++i){
//                 TreeNode* currNode = myQueue.front();
//                 myQueue.pop();
//                 currLevel.push_back(currNode->val);
//                 if (currNode->left)
//                     myQueue.push(currNode->left);
//                 if (currNode->right)
//                     myQueue.push(currNode->right);
//             }
//             res.push_back(currLevel);
//         }
//         return res;
//     }
// };

//DFS
class Solution {
private:
    vector<vector<int> > res;
    void _dfs(TreeNode* node, int level){
        if (!node) return;
        if (res.size() < level + 1){
            vector<int> temp;
            res.push_back(temp);
        }
        res[level].push_back(node->val);
        _dfs(node->left, level + 1);
        _dfs(node->right, level + 1);
    }
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        if (!root) return res;
        _dfs(root, 0);
        return res;
    }
};
// @lc code=end

