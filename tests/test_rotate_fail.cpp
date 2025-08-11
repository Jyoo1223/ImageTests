#include <gtest/gtest.h>
#include "../include/rotate.h"
using namespace cv;

class RotateFailTest : public ::testing::Test {
protected:
    void SetUp() override {
        img = Mat(100, 100, CV_8UC3, Scalar(128,128,128));
    }
    Mat img;
};

TEST_F(RotateFailTest, FailsOnChannels) {
    Mat rotated = rotateImage(img);
    // Intended to fail: channels should be equal, we assert not equal
    EXPECT_NE(rotated.channels(), img.channels());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
