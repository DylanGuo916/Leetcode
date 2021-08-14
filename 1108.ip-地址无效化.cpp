/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

// @lc code=start
#include <string>
class Solution {
public:
  string defangIPaddr(string address) {
    string ans;
    for (char a : address) {
      if (a != '.')
        ans.push_back(a);
      else
        ans.append("[.]");
    }
    return ans;
  }
};
// @lc code=end

