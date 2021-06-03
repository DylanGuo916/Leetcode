/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> res;
    int index = digits.size() - 1;
    int carry = 0;
    digits[index] = digits[index] + 1;
    while (index >= 0) {
      int sum = digits[index] + carry;
      res.push_back(sum % 10);
      carry = sum / 10;
      index--;
    }
    if (carry) 
      res.push_back(carry);
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end

