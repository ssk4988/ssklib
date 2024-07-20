#pragma once
#include "LRUCache.hpp"

LRUCache::LRUCache(size_t capacity) : capacity(capacity) {}

int LRUCache::get(int key)
{
    if (!ref.count(key))
        return -1;
    int value = ref[key]->second;
    llist.erase(ref[key]);
    ref.erase(key);
    llist.emplace_back(key, value);
    ref[key] = std::prev(llist.end());
    return ref[key]->second;
}

void LRUCache::put(int key, int value)
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
