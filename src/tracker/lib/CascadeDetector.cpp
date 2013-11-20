#include "CascadeDetector.h"

CascadeDetector::CascadeDetector(const std::string& xml_path){
    m_classifier.load(xml_path);
}

CascadeDetector::~CascadeDetector(){

}

void CascadeDetector::detect(std::vector<cv::Rect>& box_vector, cv::Mat& image){
    m_classifier.detectMultiScale(image, box_vector, 1.1, 3, 0, cv::Size(30, 30), cv::Size(100, 100));
}