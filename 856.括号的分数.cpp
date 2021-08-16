/*
 * @lc app=leetcode.cn id=856 lang=cpp
 *
 * [856] 括号的分数
 */

// @lc code=start
#include <string>
class Solution {
public:
  int scoreOfParentheses(string s) {
    return score(s, 0, s.length() - 1);
  }
private:
  int score(const std::string& s, int l, int r) {
    if (r - l == 1) return 1;
    int b = 0;
    for (int i = l; i < r; ++i) {
      if (s[i] == '(') ++b;
      if (s[i] == ')') --b;
      if (b == 0) // balanced
        return score(s, l, i) + score(s, i + 1, r);
    }
    // score("(A)") = 2 * score("A")
    return 2 * score(s, l + 1, r -1);
  }
};
// @lc code=end

