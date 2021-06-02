/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <unordered_map>
#include <vector>
#include <string>
class Automaton {
  string state = "start";
  unordered_map<string, vector<string>> table = {
      {"start", {"start", "signed", "in_number", "end"}},
      {"signed", {"end", "end", "in_number", "end"}},
      {"in_number", {"end", "end", "in_number", "end"}},
      {"end", {"end", "end", "end", "end"}}
      };

  int get_col(char c) {
    if (c == ' ')
      return 0;
    if (c == '+' or c == '-')
      return 1;
    if (c >= '0' && c <= '9')
      return 2;
    return 3;
  }

int sign = 1;
long long ans = 0;
public:
  void get(char c) {
    state = table[state][get_col(c)];
    if (state == "in_number") {
      ans = ans * 10 + c - '0';
      ans = sign == 1 ? min(ans, (long long)INT_MAX)
                      : min(ans, -(long long)INT_MIN);
    } else if (state == "signed")
      sign = c == '+' ? 1 : -1;
  }

  int getSign() {
    return sign == 1 ? 1 : -1;
  }

  long long getAns() {
    return ans;
  }
};

class Solution {
public:
    int myAtoi(string s) {
      Automaton automation;
      for (char c : s) {
        automation.get(c);
      }
      return automation.getSign() * automation.getAns(); 
    }
};
// @lc code=end

