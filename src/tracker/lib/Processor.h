#pragma once
#include <opencv2/opencv.hpp>

class Processor
{
public:
	Processor();
	~Processor();
	void load_cascade_classifier(const std::string& file_path);
	void process(cv::Mat& frame);
	void get_position(std::vector<cv::Point2f>& position_vector);
private:
	cv::CascadeClassifier m_cascade_classifier;
	std::vector<cv::Rect> m_box_vector;
};


