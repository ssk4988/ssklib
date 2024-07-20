#include <gtest/gtest.h>
#include <optional>
#include "../src/LRUCacheT.hpp"

TEST(LRUCacheTest, BasicOperations) {
    LRUCacheT<int, int> cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    ASSERT_EQ(cache.get(1), 1); 
    cache.put(3, 3); // evicts key 2
    ASSERT_EQ(cache.get(2), std::nullopt);
    ASSERT_EQ(cache.get(3), 3);
    ASSERT_EQ(cache.get(1), 1);
    cache.put(4, 4); // evicts key 3
    ASSERT_EQ(cache.get(3), std::nullopt);
    ASSERT_EQ(cache.get(4), 4);
}
