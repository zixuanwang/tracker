#include "Processor.h"

Processor::Processor(){

}

Processor::~Processor(){

}

void Processor::load_cascade_classifier(const std::string& file_path){
	m_cascade_classifier.load(file_path);
}

void Processor::process(cv::Mat& frame){
	m_cascade_classifier.detectMultiScale(frame, m_box_vector, 1.1, 3, 0, cv::Size(30, 30), cv::Size(100, 100));
}

void Processor::get_position(std::vector<cv::Point2f>& position_vector){
	if(!position_vector.empty()){
		position_vector.clear();
	}
	for(auto& box : m_box_vector){
		position_vector.push_back(cv::Point2f(box.x + box.width / 2, box.y + box.height / 2));
	}
}