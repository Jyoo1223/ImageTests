#include <gtest/gtest.h>
#include "../include/blur.h"
using namespace cv;

TEST(BlurTest, MeanIntensityShouldRemainSimilar) {
    Mat img(100, 100, CV_8UC1, Scalar(0));  
    for (int y = 0; y < img.rows; y += 20) {
        for (int x = 0; x < img.cols; x += 20) {
            Rect r(x, y, 10, 10);
            rectangle(img, r, Scalar(255), FILLED);
        }
    }

    Mat colorImg;
    cvtColor(img, colorImg, COLOR_GRAY2BGR);  

    Mat blurred = blurImage(colorImg);

    Scalar meanBefore = mean(colorImg);
    Scalar meanAfter = mean(blurred);

    for (int i = 0; i < 3; ++i) {
        EXPECT_NEAR(meanBefore[i], meanAfter[i], 5.0);  
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
