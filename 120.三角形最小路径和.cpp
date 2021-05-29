/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      if (triangle.empty())
        return 0;
      
      //巧妙复用一维数组存储
      int n = triangle.size();
      vector<int> mini = triangle[n - 1];
      for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
          mini[j] = triangle[i][j] + min(mini[j], mini[j + 1]);
        }
      }
      return mini[0];
    }
};
// @lc code=end

