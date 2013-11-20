#include "Detector.h"

Detector::Detector(){
}

Detector::~Detector(){
}

void Detector::draw(const std::vector<cv::Rect>& box_vector, cv::Mat& image){
    std::for_each(box_vector.begin(), box_vector.end(), [&](const cv::Rect& rect){cv::rectangle(image, rect, cv::Scalar(40, 40, 200), 2, CV_AA);});
}