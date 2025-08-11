#include <opencv2/opencv.hpp>
#include <iostream>

#include "blur.h"
#include "rotate.h"
#include "sobel.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Usage: demo_all_filters <image_path>" << endl;
        return -1;
    }

    Mat input = imread(argv[1]);
    if (input.empty()) {
        cout << "Error: Could not load image " << argv[1] << endl;
        return -1;
    }

    Mat blurred = blurImage(input);
    Mat rotated = rotateImage(input);
    Mat sobeled = sobelFilter(input);

    imshow("Original Image", input);
    imshow("Blurred Image", blurred);
    imshow("Rotated Image", rotated);
    imshow("Sobel Filtered Image", sobeled);

    waitKey(0);
    return 0;
}
