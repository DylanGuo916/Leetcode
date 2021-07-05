/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
      int dp[3];
      dp[0] = 0;
      dp[1] = 1;
      dp[2] = 1;
      if (n == 0)
        return 0;
      if (n == 1 || n == 2)
        return 1;
      for (int i = 0; i < n - 2; ++i) {
        int temp = dp[0];
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = temp + dp[0] + dp[1];
      }
      return dp[2];
    }
};
// @lc code=end

