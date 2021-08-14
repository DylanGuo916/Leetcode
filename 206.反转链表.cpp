/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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

// 迭代写法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      if (!head || !head->next)
        return head;
      ListNode* prev = nullptr;
      ListNode* curr = head;
      while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      return prev;
    }
};

// 递归写法
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }
};
// @lc code=end

