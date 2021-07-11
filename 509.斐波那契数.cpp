/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
      int dp[2];
      dp[0] = 1;
      dp[1] = 1;
      if (n == 0)
        return 0;
      if (n == 1 || n == 2)
        return 1;
      for (int i = 3; i <= n; ++i) {
        int temp = dp[1];
        dp[1] = dp[0] + dp[1];
        dp[0] = temp;
      }
      return dp[1];
    }
};
// @lc code=end

