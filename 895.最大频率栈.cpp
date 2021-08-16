/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] 最大频率栈
 */

// @lc code=start
#include <unordered_map>
#include <stack>
class FreqStack {
private:
  vector<stack<int>> stacks_;
  std::unordered_map<int, int> freq_;
public:
  FreqStack() {}

  void push(int val) {
    auto it = freq_.find(val);
    if (it == freq_.end())
      it = freq_.emplace(val, 0).first;
    int freq = ++it->second;
    if (stacks_.size() < freq)
      stacks_.push_back({});
    stacks_[freq - 1].push(val);
  }

  int pop() {
    int x = stacks_.back().top();
    stacks_.back().pop();
    if (stacks_.back().empty())
      stacks_.pop_back();
    auto it = freq_.find(x);
    if (!(--it->second))
      freq_.erase(it);
    return x;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

