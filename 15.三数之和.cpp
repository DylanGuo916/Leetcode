/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
private:
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> ans;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); ++i) {
        while (1) {
          int l = i + 1;
          int r = nums.size() - 1;
          if (l >= r)
            break;
          if (nums[l] + nums[r] + nums[i] == 0) {
            vector<int> tmp{nums[l], nums[r], nums[i]};
            ans.push_back(tmp);
          } else if (nums[l] + nums[r] + nums[i] < 0) {
            ++l;
          } else {
            --r;
          }
        }
      }
      return ans;
    }
};
// @lc code=end

