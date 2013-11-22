#pragma once
#include <boost/circular_buffer.hpp>
#include <boost/function.hpp>
#include <boost/shared_array.hpp>
#include <chrono>
#include <condition_variable>
#include <curl/curl.h>
#include <fstream>
#include <iostream>
#include <mutex>
#include <opencv2/opencv.hpp>
#include <queue>
#include <stdexcept>
#include <thread>
#include "Processor.h"

class Camera
{
public:
	// construct the camera by passing the ip address, username and password.
	Camera(const std::string& ip_address, const std::string& username = "", const std::string& password = "");
	virtual ~Camera(void);
	void capture();
	void get_2d_position(std::vector<cv::Point2f>& position_vector); // the 2d position of each object.
	void load_calibration(const std::string& file_path); // load intrinsic and extrinsic parameters from the xml file.
	std::string get_ip_address(){return m_ip_address;}
	void set_processor(std::shared_ptr<Processor> p){m_processor = p;}
	std::shared_ptr<Processor> get_processor(){return m_processor;}
private:
	std::string m_ip_address;
	std::string m_username;
	std::string m_password;
	CURL* m_curl_handle;
	std::vector<uchar> m_buffer;
	std::mutex m_queue_mutex;
	std::condition_variable m_condition_var;
	boost::circular_buffer<cv::Mat> m_buffer_queue; // maintain the producer consumer queue.
	bool m_stop; // indicate whether to stop the capture.
	cv::Mat m_m; // intrinsic parameter.
	cv::Mat m_dist; // distortion coefficient.
	cv::Mat m_r; // extrinsic rotation.
	cv::Mat m_t; // extrinsic translation.
	std::shared_ptr<Processor> m_processor;
	// private functions for camera class.
	static size_t invoke_frame_producer(void* ptr, size_t size, size_t nmemb, void* p_instance);
	size_t frame_producer(void* ptr, size_t size, size_t nmemb);
	cv::Mat generate_frame(unsigned char* c_ptr, size_t len);
	void save_frame(const cv::Mat& image); // save image to m_video_writer and save the according timestamp to m_timestamp_stream. called from the consumer.
	CURL* get_curl_handle(){return m_curl_handle;}
};

