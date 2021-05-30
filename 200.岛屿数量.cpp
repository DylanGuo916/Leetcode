/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
private:
  int island_num = 0;
  int max_x;
  int max_y;
  vector<int> dx{-1, 1, 0, 0};
  vector<int> dy{0, 0, -1, 1};
  vector<vector<int>> visited;
  bool _is_vaild(vector<vector<char>> &grid, int x, int y) {
    if (x < 0 || x > max_x || y < 0 || y > max_y)
      return false;
    if (gird[x][y] == '0' || visited[x][y] == true)
      return false;
    return true;
  }
  int floodfill_DFS(vector<vector<char>> &grid, int x, int y) {
    if (!_is_vaild(grid, x, y))
      return 0;
    visited[x][y] = true;
    if (grid[i][j] == '1') {
      island_num++;
    }
    else
      return;
  }

public:
    int numIslands(vector<vector<char>>& grid) {
      if (grid.empty() || grid[0].empty())
        return 0;
      max_x = gird.size();
      max_y = grid[0].size();
      for (int i = 0; i < max_x; ++i) {
        for (int j = 0; j < max_y; ++j) {

        }
      }
      return island_num;
    }
};
// @lc code=end

