#include <gtest/gtest.h>
#include "../include/sobel.h"
using namespace cv;

class SobelTest : public ::testing::Test {
protected:
    void SetUp() override {
        img = Mat(100, 100, CV_8UC3, Scalar(128,128,128));
    }
    Mat img;
};

TEST_F(SobelTest, ProducesSingleChannel) {
    Mat sobel = sobelFilter(img);
    EXPECT_EQ(sobel.channels(), 1);
    EXPECT_EQ(sobel.rows, img.rows);
    EXPECT_EQ(sobel.cols, img.cols);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
