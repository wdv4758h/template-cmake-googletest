#include <gtest/gtest.h>        // Google Test
#include <sample.h>             // Source
#include "fixtureQueue.h"       // Fixture


////////////////////////////////////////
// Simple Tests
////////////////////////////////////////

TEST(sample, HelloWorld) {  // test_case_name, test_name
    // EXPECT_* generate nonfatal failures, which don't abort the current function
    EXPECT_EQ(42, sample::life());

    // ASSERT_* generate fatal failures when they fail, and abort the current function
    ASSERT_EQ(42, sample::life());

    // STREQ for C string
    EXPECT_STREQ("Hello World", sample::helloWorld());
    // can use "<<" to add additional messages
    EXPECT_STREQ("Hello World!", sample::helloWorld()) << "Custom Failure Message";
    EXPECT_STREQ("Hello World!", sample::helloWorld()) << "你寫錯了！";

    ////////////////////////////////////////
    // Basic
    ////////////////////////////////////////
    //
    // ASSERT_TRUE,         EXPECT_TRUE
    // ASSERT_FALSE,        EXPECT_FALSE
    //
    ////////////////////////////////////////
    // Binary Comparison
    ////////////////////////////////////////
    //
    // ASSERT_EQ,           EXPECT_EQ
    // ASSERT_NE,           EXPECT_NE
    // ASSERT_LT,           EXPECT_LT
    // ASSERT_LE,           EXPECT_LE
    // ASSERT_GT,           EXPECT_GT
    // ASSERT_GE,           EXPECT_GE
    //
    ////////////////////////////////////////
    // C String Comparison
    ////////////////////////////////////////
    //
    // ASSERT_STREQ,        EXPECT_STREQ
    // ASSERT_STRNE,        EXPECT_STRNE
    // ASSERT_STRCASEEQ,    EXPECT_STRCASEEQ    // case insensitive
    // ASSERT_STRCASENE,    EXPECT_STRCASENE
}


////////////////////////////////////////
// Use Fixtures
////////////////////////////////////////

TEST_F(QueueTest, IsEmptyInitially) {   // TEST_F(fiture_name, test_name)
    EXPECT_EQ(0ul, q0.size());    // q0 comes from the fixture
}


////////////////////////////////////////
// Parameter
////////////////////////////////////////
//
// Range(begin, end[, step])
// Values(v1, v2, ..., vN)
// ValuesIn(container)
// ValuesIn(begin, end)
// Bool()
// Combine(g1, g2, ..., gN)

class ParamTest: public ::testing::TestWithParam<int> {};
TEST_P(ParamTest, IsEven) {
    EXPECT_TRUE(GetParam() % 2 == 0);
}
INSTANTIATE_TEST_CASE_P(GenParam,       // test case name prefix
                        ParamTest,
                        ::testing::Range(1, 10));
