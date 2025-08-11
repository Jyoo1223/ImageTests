#include "rotate.h"

Mat rotateImage(const Mat& input) {
    Mat output;
    rotate(input, output, ROTATE_90_CLOCKWISE);
    return output;
}
