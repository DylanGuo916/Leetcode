/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
#include <vector>
class Solution {
private:
    bool isInArea(int ax1, int ay1, int ax2, int ay2, int x, int y){
        if(x > ax1 && x < ax2 && y > ay1 && y < ay2)
            return true;
        return false;
    }
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
      int totalArea = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
      if (ax1 > bx2 || ax2 < bx1 || ay1 > by2 || ay2 < by1)
        return totalArea;
      int a[] = {ax1, ax2, bx1, bx2};
      int b[] = {ay1, ay2, by1, by2};
      std::vector<int> xOf2Rectangle(a, a + 4);
      std::vector<int> yOf2Rectangle(b, b + 4);
      return totalArea - (xOf2Rectangle[2] - xOf2Rectangle[1]) *
                             (yOf2Rectangle[2] - yOf2Rectangle[1]);
    }
};
// @lc code=end

