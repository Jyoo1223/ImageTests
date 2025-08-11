#include <gtest/gtest.h>
#include "../include/blur.h"
using namespace cv;

class BlurTest : public ::testing::Test {
protected:
    void SetUp() override {
        img = Mat(100, 100, CV_8UC3, Scalar(128,128,128));
    }
    Mat img;
};

TEST_F(BlurTest, ProducesSameSize) {
    Mat blurred = blurImage(img);
    EXPECT_EQ(blurred.rows, img.rows);
    EXPECT_EQ(blurred.cols, img.cols);
    EXPECT_EQ(blurred.channels(), img.channels());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
