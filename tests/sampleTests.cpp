#include <gtest/gtest.h>
#include <sample.h>

TEST(sample, HelloWorld) {
    EXPECT_STREQ("Hello World", sample::helloWorld());
}
