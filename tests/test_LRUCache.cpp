#include <gtest/gtest.h>
#include "../src/LRUCache.hpp"

TEST(LRUCacheTest, BasicOperations) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    ASSERT_EQ(cache.get(1), 1); 
    cache.put(3, 3); // evicts key 2
    ASSERT_EQ(cache.get(2), -1);
    ASSERT_EQ(cache.get(3), 3);
    ASSERT_EQ(cache.get(1), 1);
    cache.put(4, 4); // evicts key 3
    ASSERT_EQ(cache.get(3), -1);
    ASSERT_EQ(cache.get(4), 4);
}

