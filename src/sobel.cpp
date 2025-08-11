#include "sobel.h"

Mat sobelFilter(const Mat& input) {
    Mat gray, grad_x, grad_y, abs_grad_x, abs_grad_y, output;
    cvtColor(input, gray, COLOR_BGR2GRAY);
    Sobel(gray, grad_x, CV_16S, 1, 0);
    Sobel(gray, grad_y, CV_16S, 0, 1);
    convertScaleAbs(grad_x, abs_grad_x);
    convertScaleAbs(grad_y, abs_grad_y);
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, output);
    return output;
}
