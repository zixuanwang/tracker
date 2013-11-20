#pragma once

#include "Detector.h"

class CascadeDetector : public Detector
{
public:
	CascadeDetector(const std::string& xml_path);
	~CascadeDetector();
	void detect(std::vector<cv::Rect>& box_vector, cv::Mat& image);
private:
	cv::CascadeClassifier m_classifier;
};

