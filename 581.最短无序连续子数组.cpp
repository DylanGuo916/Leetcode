/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      vector<int> snums(nums.begin(), nums.end());
      sort(snums.begin(), snums.end());
      int start = snums.size();
      
    }
};
// @lc code=end
