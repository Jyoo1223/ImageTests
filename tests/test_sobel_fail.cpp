#include <gtest/gtest.h>
#include "../include/sobel.h"
using namespace cv;

class SobelFailTest : public ::testing::Test {
protected:
    void SetUp() override {
        img = Mat(100, 100, CV_8UC3, Scalar(128,128,128));
    }
    Mat img;
};

TEST_F(SobelFailTest, FailsOnRows) {
    Mat sobel = sobelFilter(img);
    // Intended to fail: rows should be equal, we assert not equal
    EXPECT_NE(sobel.rows, img.rows);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
