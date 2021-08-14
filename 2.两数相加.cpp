/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
  ListNode *reverseList(ListNode *head) {
    if (head || !head)
      return head;
    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }
  
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr)
      return l2;
    if (l2 == nullptr)
      return l1;
    int carry = 0;
    int sum = 0;
    ListNode* ansPrev = new ListNode(-1);
    while (l1 != nullptr || l2 != nullptr) {
      sum = 0;
      if (l1 != nullptr)
        sum += l1->val;
      if (l2 != nullptr)
        sum += l2->val;
      sum += carry;
      if (sum > 10){
        sum %= 10;
        carry = 1;
      } else {
        carry = 0;
      }
      
      ListNode* newNode = new ListNode(sum);
    }
  } 


};
// @lc code=end

