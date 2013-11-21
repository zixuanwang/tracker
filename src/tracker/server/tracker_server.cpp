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
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include "server.hpp"
#include "tracker/lib/Camera.h"

void exit_with_help() {
	std::cout
		<< "Usage: tracker_server\n";
	exit(1);
}

int main(int argc, char* argv[]){
	if(argc == 1){
		exit_with_help();
	}
	try{
		http::server3::server s("0.0.0.0", "80", "/", 1);
		s.run();
	}catch(std::exception& e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	boost::property_tree::ptree pt;
	boost::property_tree::ptree children;
	boost::property_tree::ptree child1, child2, child3;

	child1.put("", 1);
	child2.put("", 2);
	child3.put("", 3);

	children.push_back(std::make_pair("", child1));
	children.push_back(std::make_pair("", child2));
	children.push_back(std::make_pair("", child3));

	pt.add_child("MyArray", children);
	std::stringstream ss;
	boost::property_tree::json_parser::write_json(ss, pt);
	std::cout << ss.str() << std::endl;
	return 0;
}