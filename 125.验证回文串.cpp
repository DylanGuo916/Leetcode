/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <cctype>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
      int n = s.length();
      int left = 0, right = n - 1;
      while (left < right) {
        while (left < right && !isdigit(s[left]) && !isalpha(s[left])) {
          ++left;
        }
        while (left < right && !isdigit(s[right]) && !isalpha(s[right])) {
          --right;
        }
        if (left < right) {
          if (tolower(s[left]) != tolower(s[right])) {
            return false;
          }
          ++left;
          --right;
        }
      }
      return true;
    }
};
// @lc code=end

