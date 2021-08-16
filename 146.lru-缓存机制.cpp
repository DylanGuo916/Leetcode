/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
class LRUCache {
public:
  LRUCache(int capacity) {
    m_capacity = capacity;
  }
  
  int get(int key) {
    const auto it = m_hashtable.find(key);
    // If key does not exist
    if (it == m_hashtable.cend()) return -1;
    // Move this key to the front of the list
    m_cache.splice(m_cache.begin(), m_cache, it->second);
    return it->second->second;
  }
  
  void put(int key, int value) {
    const auto it = m_shashtable.find(key);
    // key already exists
    if (it != m_hashtable.cend()) {
      it->second->second = value;
      m_cache.splice(m_cache.begin(), m_cache, it->second);
      return;
    }

    // key does not exist 
    // reached the capacity, remove the oldest element
    if (m_cache.size() == m_capacity) {
      const auto& node = m_cache.back();
      m_hashtable.erase(node.first);
      m_cache.pop_back();
    }

    m_cache.emplace_front(key, value);
    m_hashtable[key] = m_cache.begin();
  }
private:
  int m_capacity;
  list<pair<int, int>> m_cache;
  unordered_map<int, list<pair<int, int>>::iterator> m_hashtable;
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

