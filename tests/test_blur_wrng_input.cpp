#include <gtest/gtest.h>
#include "../include/blur.h"
using namespace cv;

TEST(BlurTest, HandlesEmptyInputGracefully) {
    Mat emptyImg;
    Mat blurred = blurImage(emptyImg);

    EXPECT_TRUE(blurred.empty());  
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
