#pragma once
#include <list>
#include <unordered_map>

namespace ssk
{
    class LRUCache
    {
    private:
        std::list<std::pair<int, int>> llist;
        std::unordered_map<int, std::list<std::pair<int, int>>::iterator> ref;

    public:
        size_t capacity;
        LRUCache(size_t capacity);
        int get(int key);
        void put(int key, int value);
    };
}
