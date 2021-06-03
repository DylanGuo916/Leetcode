/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
#include <algorithm>
#include <string>
class Solution {
public:
  string convertToTitle(int columnNumber) {
    string s = "";
    while (columnNumber > 0) {
      columnNumber -= 1;
      s += 'A' + columnNumber % 26;
      columnNumber /= 26;
    }
    reverse(s.begin(), s.end());
    return s;
  }
};
// @lc code=end
