/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
#include <unordered_map>
#include <set>

struct CacheNode {
  int key;
  int value;
  int freq;
  long tick;

  bool operator < (const CacheNode& other) {
    if (freq < other.freq) return true;
    if (freq == other.freq)
      return tick < other.tick;
    return false;
  }
};

class LFUCache {
public:
    LFUCache(int capacity) {
      m_capacity = capacity;
    }
    
    int get(int key) {
      auto it = m_hashtable.find(key);
      if (it == m_hashtable.cend()) return -1;
      int value = it->second.value;
      touch(it->second);
      return value;
    }
    
    void put(int key, int value) {
      if (m_capacity == 0) return;
      auto it = m_hashtable.find(key);

      if (it != m_hashtable.cend()) {
        it->second.value = value;
        touch(it->second);
        return;
      }

      if (m_hashtable.size() == m_capacity) {
        const CacheNode& node = *m_cache.cbegin();
        m_hashtable.erase(node.key);
        m_cache.erase(node);
      }

      CacheNode node{key, value, 1, ++m_tick};
      m_hashtable[node.key] = node;
      m_cache.insert(node);
    }
private:
  void touch(CacheNode& node) {
    m_cache.erase(node);
    ++node.freq;
    node.tick = ++m_tick;
    m_cache.insert(node);
  }

  long m_tick;
  int m_capacity;
   std::unordered_map<int, CacheNode> m_hashtable;
   std::set<CacheNode> m_cache;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

