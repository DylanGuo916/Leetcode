/*
 * @lc app=leetcode.cn id=1095 lang=cpp
 *
 * [1095] 山脉数组中查找目标值
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

#include <algorithm>
#include <atomic>
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
      const int n = mountainArr.length();
      auto binary_search = [&](int l, int r, function<bool(int)> cond) {
        while (l < r) {
          int mid = l + (r - l) / 2;
          if (cond(mid)) r = mid;
          else l = mid + 1;
        }
        return l;
      };

      int p = binary_search(0, n - 1, [&](int i)->bool{
        return mountainArr.get(i) > mountainArr.get(i + 1);
      });

      int l = binary_search(0, p, [&](int i)->bool {
        return mountainArr.get(i) >= target;
      });
      if (mountainArr.get(l) == target) return l;

      int r = binary_search(p, n - 1, [&](int i)->bool {
        return mountainArr.get(i) <= target;
      });
      if (mountainArr.get(r) == target) return r;
      return -1;
    }
};
// @lc code=end

