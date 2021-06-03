/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_set<int> existed;
    int n = nums.size();
    int curr = 0;
    for (int i = 0; i < n; ++i) {
      curr = nums[i];
      if (existed.find(curr) == existed.end()) {
        existed.insert(curr);
        if (existed.size() > k) {
          existed.erase(nums[i - k]);
        }
      } else {
        return true;
      }
    }

    return false;
  }
};
// @lc code=end
