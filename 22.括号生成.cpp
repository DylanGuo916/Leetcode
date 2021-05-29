/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
  vector<string> res;
  void _gen(int left_used, int right_used, int n, string result) {
    if (left_used == n && right_used == n) {
      res.emplace_back(result);
      return;
    }
    if (left_used < n) {
      _gen(left_used + 1, right_used, n, result + "(");
    }
    if (left_used > right_used && right_used < n) {
      _gen(left_used, right_used + 1, n, result + ")");
    }
  }
public:
  vector<string> generateParenthesis(int n) {
    _gen(0, 0, n, "");
    return res;
  }  
};
// @lc code=end
