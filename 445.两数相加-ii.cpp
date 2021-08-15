/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *r1 = reverseList(l1);
    ListNode *r2 = reverseList(l2);
    ListNode dummy(0);
    ListNode *tail = &dummy;
    int sum = 0;
    while (r1 || r2 || sum) {
      sum += (r1 ? r1->val : 0) + (r2 ? r2->val : 0);
      r1 = r1 ? r1->next : nullptr;
      r2 = r2 ? r2->next : nullptr;
      tail->next = new ListNode(sum % 10);
      sum /= 10;
      tail = tail->next;
    }
    return reverseList(dummy.next);
  }

  ListNode *reverseList(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }
};
// @lc code=end

