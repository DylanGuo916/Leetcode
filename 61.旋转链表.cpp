/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head) return head;
    int l = 1;
    ListNode* tail = head;
    while (tail->next) {
      tail = tail->next;
      ++l;
    }
    k %= l;
    if (k == 0) return head;

    ListNode* prev = head;
    while (--l > k)
    
  }
};
// @lc code=end

