#include <queue>
#include <gtest/gtest.h>


class QueueTest: public ::testing::Test {
protected:
    virtual void SetUp() {
        q1.push(1);
        q2.push(2);
        q2.push(3);
    }

    virtual void TearDown() {}

    std::queue<int> q0;
    std::queue<int> q1;
    std::queue<int> q2;
};
