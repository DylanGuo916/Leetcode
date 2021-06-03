/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
#include <algorithm>
#include <string>
class Solution {
public:
  string reverseWords(string s) {
    int n = s.length();
    int slow = 0, fast = 0;
    while (fast < n) {
      slow = fast;
      while (fast < n && s[fast] != ' ') 
        ++fast;
      int left = slow, right = fast - 1;
      while (left < right) {
        std::swap(s[left], s[right]);
        ++left;
        --right;
      }
      while (fast < n && s[fast] == ' ')
        ++fast;
    }
    return s;
  }
};
// @lc code=end

