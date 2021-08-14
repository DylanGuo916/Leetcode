/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      std::unordered_map<int, int> nums_map;
      int n = nums.size();
      for (int i = 0; i < n; ++i) {
        if (nums_map.find(target - nums[i]) != nums_map.end()) {
          return {nums_map[target - nums[i]], i};
        } else {
          nums_map.insert({nums[i], i});
        }
      }
      return {};
    }
};
// @lc code=end

