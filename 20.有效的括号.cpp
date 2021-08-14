/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <stack>
class Solution {
public:
    bool isValid(string s) {
      for (char i : s) {
        if (i == '(' || i == '[' || i == '{') {
          myStack.push(i);
        } else if (i == ')') {
          if (myStack.empty() || myStack.top() != '(')
            return false;
          myStack.pop();
        } else if (i == ']') {
          if (myStack.empty() || myStack.top() != '[')
            return false;
          myStack.pop();
        } else if (i == '}') {
          if (myStack.empty() || myStack.top() != '{')
            return false;
          myStack.pop();
        }
      }
      if (!myStack.empty())
        return false;
      return true;
    }
private:
  stack<char> myStack;
};
// @lc code=end

