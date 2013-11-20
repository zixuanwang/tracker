#pragma once

#include <opencv2/opencv.hpp>

class Detector
{
public:
	Detector();
	virtual ~Detector();
	virtual void detect(std::vector<cv::Rect>& box_vector, cv::Mat& image) = 0;
	void draw(const std::vector<cv::Rect>& box_vector, cv::Mat& image);
};

