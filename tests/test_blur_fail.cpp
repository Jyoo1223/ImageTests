#include <gtest/gtest.h>
#include "../include/blur.h"
using namespace cv;

class BlurFailTest : public ::testing::Test {
protected:
    void SetUp() override {
        img = Mat(100, 100, CV_8UC3, Scalar(128,128,128));
    }
    Mat img;
};

TEST_F(BlurFailTest, FailsOnWrongSize) {
    Mat blurred = blurImage(img);
    EXPECT_NE(blurred.rows, img.rows);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
