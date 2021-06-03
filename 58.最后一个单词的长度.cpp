/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
  int lengthOfLastWord(string s) {
    int len = 0;
    for (auto it = s.rbegin(); it != s.rend(); it++) {
      if (isalpha(*it))
        len++;
      if (len > 0 && !isalpha(*(it + 1)))
        return len;
    }
    return 0;
  }
};
// @lc code=end
