/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
  int addDigits(int num) {
    while (num >= 10) {
      num = DigitsSum(num);
    }
    return num;
  }
private:
  int DigitsSum(int num) {
    int ans = 0;
    while (num) {
      ans += num % 10;
      num /= 10;
    }
    return ans;
  } 
};
// @lc code=end

