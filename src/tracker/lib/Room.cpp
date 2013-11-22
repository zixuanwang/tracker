#include "Room.h"

std::string Room::CASCADE_FOLDER = "C:/Users/danwa/Dropbox/data/iroom/calibrate";
Room* Room::s_instance = NULL;

Room::Room() : m_count(0){
	curl_global_init(CURL_GLOBAL_ALL);
}

Room* Room::instance(){
	if(s_instance == NULL){
		s_instance = new Room();
	}
	return s_instance;
}

void Room::init(const std::string& config_path){
	std::ifstream in_stream;
	in_stream.open(config_path);
	if(in_stream.good()){
		std::string username;
		std::string password;
		// read username and password
		getline(in_stream, username);
		getline(in_stream, password);
		// read ip_address
		std::string ip_address;
		while(getline(in_stream, ip_address)){
			std::shared_ptr<Camera> p_camera(new Camera(ip_address, username, password));
			m_camera_array.push_back(p_camera);
		}
		in_stream.close();
	}
}

void Room::run(){
	std::vector<std::shared_ptr<std::thread> > thread_ptr_array;
	for(size_t i = 0; i < m_camera_array.size(); ++i){
		thread_ptr_array.push_back(std::shared_ptr<std::thread>(new std::thread([&, i](){
			std::shared_ptr<Processor> p(new Processor);
			p->load_cascade_classifier(CASCADE_FOLDER + "/" + m_camera_array[i]->get_ip_address() + "/camera.xml");
			m_camera_array[i]->set_processor(p);
			m_camera_array[i]->capture();
		})));
	}
	std::for_each(thread_ptr_array.begin(), thread_ptr_array.end(), [](std::shared_ptr<std::thread>& p){p->join();});
}

void Room::get_2d_position(std::vector<cv::Point2f>& position_vector){
	if(!position_vector.empty()){
		position_vector.clear();
	}
	for(size_t i = 0; i < m_camera_array.size(); ++i){
		std::vector<cv::Point2f> vector;
		m_camera_array[i]->get_2d_position(vector);
		std::copy(vector.begin(), vector.end(), std::back_inserter(position_vector));
	}
}
