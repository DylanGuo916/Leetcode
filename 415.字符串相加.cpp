/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
#include <string>
class Solution {
public:
    string addStrings(string num1, string num2) {
      int len1 = num1.length();
      int len2 = num2.length();
      if (len1 < len2)
        return addStrings(num2, num1);
      int carry = 0;
      int i = len1 - 1;
      while (i >= 0) {
        num1[i] += 
      }
    }
};
// @lc code=end

