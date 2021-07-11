/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
  ListNode* getMedian(ListNode* left, ListNode* right) {
    ListNode* fast = left;
    ListNode* slow = left;
    while (fast != right && fast->next != right) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }

  TreeNode* sortedListToBST(ListNode* left, ListNode* right) {
    if (left == right)
      return nullptr;
    ListNode* mid = getMedian(left, right);
    TreeNode* root = new TreeNode(mid->val);
    root->left = sortedListToBST(left, mid);
    root->right = sortedListToBST(mid->next, right);
    return root;
  }
  TreeNode* sortedListToBST(ListNode* head) {
    return sortedListToBST(head, nullptr);
  }
};
// @lc code=end

