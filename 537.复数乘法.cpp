/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
      int index1 = num1.find('+') - num1.begin();
      int index2 = num2.find('+') - num2.begin();
      int index3 = num1.find('i') - num1.begin();
      int index4
      const char *r1 = num1.substr(0, index1);
      const char *r2 = num1.substr(0, index2);
      int real1 = atoi(r1);
      int real2 = atoi(r2);

    }
};
// @lc code=end

