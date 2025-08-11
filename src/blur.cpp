#include "blur.h"

Mat blurImage(const Mat& input) {
    Mat output;
    GaussianBlur(input, output, Size(5,5), 1.5);
    return output;
}
