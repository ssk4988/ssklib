#include <gtest/gtest.h>
#include "../src/deque.hpp"

TEST(DequeTest, BasicOperations) {
    ssk::deque<int> dq;
    dq.push_back(5);
    dq.push_front(2);
    ASSERT_EQ(dq[0], 2);
    ASSERT_EQ(dq[1], 5);
}
