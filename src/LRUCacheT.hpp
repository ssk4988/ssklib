#pragma once
#include <list>
#include <unordered_map>
#include <optional>
#include <cassert>

namespace ssk
{
    template <typename K, typename V>
    class LRUCacheT
    {
    private:
        std::list<std::pair<K, V>> llist;
        std::unordered_map<K, typename std::list<std::pair<K, V>>::iterator> ref;

    public:
        size_t capacity;
        LRUCacheT(size_t capacity) : capacity(capacity)
        {
            assert(capacity > 0);
        }
        std::optional<V> get(K key)
        {
            if (!ref.count(key))
                return std::nullopt;
            V value = std::move(ref[key]->second);
            llist.erase(ref[key]);
            llist.emplace_back(key, std::move(value));
            ref[key] = std::prev(llist.end());
            return ref[key]->second;
        }
        void put(K key, V value)
        {
            if (ref.count(key))
            {
                llist.erase(ref[key]);
                ref.erase(key);
            }
            if (ref.size() == capacity)
            {
                ref.erase(llist.front().first);
                llist.pop_front();
            }
            llist.emplace_back(key, value);
            ref[key] = std::prev(llist.end());
        }
    };
}
