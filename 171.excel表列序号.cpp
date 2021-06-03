/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
#include <cmath>
class Solution {
public:
    int titleToNumber(string columnTitle) {
      int n = columnTitle.length();
      int sum = 0;
      // for (int i = 0; i < n; ++i) {
      //   sum *= 26;
      //   sum += columnTitle[i] - 'A' + 1;
      // }
      for (int i = n - 1; i >= 0; --i) {
        int digit = columnTitle[i] - 'A' + 1;
        sum += digit * pow(26, n - i -1);
      }
      return sum;
    }
};
// @lc code=end

