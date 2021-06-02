/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
      ListNode *sentinel = new ListNode(0);
      sentinel->next = head;

      ListNode *prev = sentinel;
      ListNode *curr = head;
      ListNode *toDelete = nullptr;
      
      while (curr != nullptr) {
        if (curr->val == val) {
          prev->next = curr->next;
          toDelete = curr;
        } else prev = curr;

        curr = curr->next;
        if (toDelete != nullptr) {
          delete toDelete;
          toDelete = nullptr;
        }
      }
      
      ListNode *ret = sentinel->next;
      delete sentinel;
      return ret;
    }
};
// @lc code=end

