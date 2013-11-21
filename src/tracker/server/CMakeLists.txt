ADD_EXECUTABLE(tracker_server 
	connection.hpp connection.cpp
	header.hpp
	mime_types.hpp mime_types.cpp
	reply.hpp reply.cpp
	request_handler.hpp request_handler.cpp
	request_parser.hpp request_parser.cpp
	server.hpp server.cpp
	tracker_server.cpp)

TARGET_LINK_LIBRARIES(tracker_server libtracker)