/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
#include <algorithm>
#include <iterator>
#include <string>
class Solution {
public:
  string addStrings(string num1, string num2) {
    std::reverse(std::begin(num1), std::end(num1));
    std::reverse(std::begin(num2), std::end(num2));
    string ans;
    int len1 = num1.length();
    int len2 = num2.length();
    int i = 0; int j = 0;
    int sum = 0;
    while (i < len1 || j < len2  || sum) {
      if (i < len1) sum = sum + num1[i] - '0';
      if (j < len2) sum = sum + num2[j] - '0';
      ++i; ++j;
      char tmp = '0' + sum % 10;
      ans.push_back(tmp);
      sum /= 10;
    }
    std::reverse(std::begin(ans), std::end(ans));
    return ans;
  }
};
// @lc code=end

