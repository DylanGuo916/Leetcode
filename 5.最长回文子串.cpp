/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
      int n = s.length();
      if (n < 2)
        return s;
      
      vector<vector<bool>> dp(n, vector<bool>(n));
      for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
      }

      int maxLen = 1;
      int begin = 0;
      for (int L = 2; L <= n; ++L) {
        for (int i = 0; i < n; ++i) {
          int j = i + L - 1;
          if (j >= n)
            break;
          if (s[i] != s[j])
            dp[i][j] = false;
          else {
            if (L == 2)
              dp[i][j] = true;
            else {
              dp[i][j] = dp[i + 1][j - 1];
            }
          }
          if (dp[i][j] == true && L > maxLen) {
            maxLen = L;
            begin = i;
          }
        }
      }
      return s.substr(begin, maxLen);
    }
};
// @lc code=end

