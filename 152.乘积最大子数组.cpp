/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
#include <memory>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
      if (nums.empty()) return 0;
      int res = nums[0];
      int dp[2][2];
      dp[0][0] = nums[0];
      dp[0][1] = nums[0];
      for (int i = 1; i < nums.size(); ++i) {
        int x = i % 2;
        int y = (i - 1) % 2;

        dp[x][0] = max(dp[y][0] * nums[i], max(dp[y][1] * nums[i], nums[i]));
        dp[x][1] = min(dp[y][0] * nums[i], min(dp[y][1] * nums[i], nums[i]));
        res = max(dp[x][0], res);
      }
      return res;
    }
};
// @lc code=end

