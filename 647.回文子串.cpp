/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
      int n = s.length();
      if (n <= 0)
        return 0;
      if (n == 1)
        return 1;
      int dp[n][n];
      // vector<vector<bool>> dp(n, vector<bool>(n, false));
      int ans = 0;
      for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
      }
      for (int l = 2; l <= n; ++l){
        for (int i = 0; i < n; ++i) {
          int j = i + l - 1;
          if (j >= n)
            continue;
          if (s[i] != s[j]) {
            dp[i][j] = false;
          } else if (l == 2) {
            dp[i][j] = true;
          } else {
            dp[i][j] = dp[i + 1][j - 1];
          }
        }
      }

      for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
          if (dp[i][j] == true)
            ++ans;
        }
      }
      return ans;
    }
};
// @lc code=end

