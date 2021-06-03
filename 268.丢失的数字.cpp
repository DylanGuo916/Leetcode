/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
#include <vector>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      vector<int> helper;
      for (int i = 0; i <= nums.size(); ++i)
        helper.push_back(i);
      return accumulate(helper.begin(), helper.end(), 0) -
             accumulate(nums.begin(), nums.end(), 0);
    }
};
// @lc code=end

