/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class MonotonicQueue {
public:
  void push(int e) {
    while (!m_data.empty() && e > m_data.back())
      m_data.pop_back();
    m_data.push_back(e);
  }

  void pop() {
    m_data.pop_front();
  }

  int max() {
    return m_data.front();
  }
private:
  deque<int> m_data;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      MonotonicQueue q;
      vector<int> ans;
      for (int i = 0; i < nums.size(); ++i) {
        q.push(nums[i]);
        if (i - k + 1 >= 0) {
          ans.push_back(q.max());
          if (nums[i - k + 1] == q.max()) q.pop();
        } 
      }
      return ans;
    }
};
// @lc code=end

