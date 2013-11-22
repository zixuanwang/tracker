//
// main.cpp
// ~~~~~~~~
//
// Copyright (c) 2003-2013 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include "server.hpp"
#include "tracker/lib/Room.h"

void exit_with_help() {
	std::cout
		<< "Usage: tracker_server config.dat\n";
	exit(1);
}

int main(int argc, char* argv[]){
	if(argc == 1){
		exit_with_help();
	}
	try{
		Room::instance()->init(argv[1]);
		Room::instance()->run();
		//std::thread room_thread([&]{
		//	Room::instance()->init(argv[1]);
		//	Room::instance()->run();
		//});
		//std::thread server_thread([&]{
		//	http::server3::server s("0.0.0.0", "80", "/", 1);
		//	s.run();
		//});
		//room_thread.join();
		//server_thread.join();
	}catch(std::exception& e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}