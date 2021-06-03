/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
    int firstUniqChar(string s) {
      int n = s.length();
      unordered_map<char, int> charTable;
      for (int i = 0; i < n; ++i) {
        if (charTable.find(s[i]) != charTable.end())
          charTable[s[i]] = -1;
        else
          charTable[s[i]] = 1;
      }
      for (int i = 0; i < n; ++i) {
        if (charTable[s[i]] == 1)
          return i;
      }
      return -1;
    }
};
// @lc code=end

