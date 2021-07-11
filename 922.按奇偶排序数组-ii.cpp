/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
#include <vector>
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
      int i = 0;
      int j = 1;
      while (i < nums.size() && j < nums.size()) {
        if (nums[i] % 2 == 1) {
          while (nums[j] % 2 == 1)
            j += 2;
          int temp = nums[i];
          nums[i] = nums[j];
          nums[j] = temp;
        }
        i += 2;
      }
      return nums;
    }
};
// @lc code=end

