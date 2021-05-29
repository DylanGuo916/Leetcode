/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <algorithm>
#include <cmath>
#include <type_traits>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      //DP 时间复杂度O(N^2)
      // if(nums.empty())
      //   return 0;
      // int n = nums.size();
      // int res = 1;
      // int dp[n];
      // for (int i = 0; i < n; ++i)
      //   dp[i] = 1;

      // for(int i = 0; i < n; ++i) {
      //   for (int j = 0; j < i; ++j) {
      //     if (nums[j] < nums[i]) {
      //       dp[i] = max(dp[j] + 1, dp[i]);
      //     }
      //   }
      //   res = max(res, dp[i]);
      // }
      // return res;

      //维护最长上升子序列
      vector<int> LIS;
      for (int i = 0; i < nums.size(); ++i) {
        auto it = lower_bound(LIS.begin(), LIS.end(), nums[i]);
        if (it == LIS.end())
          LIS.push_back(nums[i]);
        else
          *it = nums[i];
      }
      return LIS.size();
    }
};
// @lc code=end

