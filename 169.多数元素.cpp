/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> myMap;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            myMap[nums[i]]++;
        int res = 0;
        for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
            if(iter->second > n/2)
                res = iter->first;
        }
        return res;
    }
};
// @lc code=end

