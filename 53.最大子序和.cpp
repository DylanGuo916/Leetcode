/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
private:
  int maxSum;
public:
    int maxSubArray(vector<int>& nums) {
      int n = nums.size();
      if (n == 0)
        return 0;
      vector<int> dp(n);
      dp[0] = nums[0];
      maxSum = nums[0];
      
      for (int i = 1; i < n; ++i) {
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        maxSum = max(dp[i], maxSum);
      }
      return maxSum;
    }
};
// @lc code=end

