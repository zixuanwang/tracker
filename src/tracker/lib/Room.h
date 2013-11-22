#pragma once

#include <algorithm>
#include <boost/bind.hpp>
#include <memory>
#include "Camera.h"
#include "Processor.h"

class Room
{
public:
	static Room* instance();
	// load configuration from the file.
	// the first line of the configuration file is username. the second line is password.
	// the rest lines are ip addresses.
	void init(const std::string& config_path);
	void run();
	void get_2d_position(std::vector<cv::Point2f>& position_vector);
	int get_count(){return m_count;}
	// global variables
	static std::string CASCADE_FOLDER;
private:
	Room();
	Room(const Room&);
	Room& operator=(const Room&);
	static Room* s_instance;
	std::vector<std::shared_ptr<Camera> > m_camera_array;
	int m_count; // the number of objects in the room.
};


