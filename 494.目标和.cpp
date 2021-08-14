/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <vector>
#include <numeric>
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      const int n = nums.size();
      const int sum = accumulate(nums.begin(), nums.end(), 0);
      if (sum < abs(target)) return 0;
      vector<int> dp(2 * sum + 1, 0);
      for (int i = 0; i < n; ++i) {
      }
    }
};
// @lc code=end

