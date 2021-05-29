/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <numeric>
class Solution {
private:
  std::vector<int> numOf2;
  std::vector<int> numOf5;
  void divideBy2(int n) {
      while (n >= 2) {
          n /= 2;
          numOf2.push_back(n);
        }
    }
    void divideBy5(int n){
        while(n >= 5){
            n /= 5;
            numOf5.push_back(n);
        }
    }
public:
    int trailingZeroes(int n) {
        divideBy2(n);
        divideBy5(n);
        return std::min(accumulate(numOf2.begin(), numOf2.end(), 0),
                      accumulate(numOf5.begin(), numOf5.end(), 0));
    }
};
// @lc code=end

