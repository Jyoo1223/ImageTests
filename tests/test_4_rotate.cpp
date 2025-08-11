#include <gtest/gtest.h>
#include "../include/rotate.h"
using namespace cv;

TEST(RotateTest, RotateFourTimesReturnsOriginal) {
    Mat img = imread("test.webp");  
    ASSERT_FALSE(img.empty()) << "Image not found!";

    Mat rotated = img.clone();
    for (int i = 0; i < 4; ++i) {
        rotated = rotateImage(rotated);
    }

    EXPECT_EQ(rotated.size(), img.size());
    EXPECT_EQ(rotated.type(), img.type());

    Mat diff;
    absdiff(rotated, img, diff);
    EXPECT_EQ(countNonZero(diff.reshape(1)), 0) << "Image differs after 4 rotations";
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
