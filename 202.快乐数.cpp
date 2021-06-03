/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
    bool isHappy(int n) {
      unordered_set<int> numTable;
      while (n != 1) {
        if (numTable.count(n) == 0)
          numTable.insert(n);
        else
          return false;
        n = digitSquareSum(n);
      }
      return true;
    }
    int digitSquareSum(int n) {
      int sum = 0;
      while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
      }
      return sum;
    }
};
// @lc code=end

