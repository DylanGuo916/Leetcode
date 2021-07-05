/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
      int dp[2];
      dp[0] = 1;
      dp[1] = 2;
      if (n == 1)
        return 1;
      if (n == 2)
        return 2;
      for (int i = 3; i <= n; ++i) {
        int temp = dp[0];
        dp[0] = dp[1];
        dp[1] += temp;
      }
      return dp[1];
    }
};
// @lc code=end

