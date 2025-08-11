#include <gtest/gtest.h>
#include "../include/rotate.h"
using namespace cv;

class RotateTest : public ::testing::Test {
protected:
    void SetUp() override {
        img = Mat(100, 100, CV_8UC3, Scalar(128,128,128));
    }
    Mat img;
};

TEST_F(RotateTest, ProducesCorrectSize) {
    Mat rotated = rotateImage(img);
    EXPECT_EQ(rotated.rows, img.cols);
    EXPECT_EQ(rotated.cols, img.rows);
    EXPECT_EQ(rotated.channels(), img.channels());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
