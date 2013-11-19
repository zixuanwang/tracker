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

int main(int argc, char* argv[])
{
	//try
	//{
	//	// Check command line arguments.
	//	if (argc != 5)
	//	{
	//		std::cerr << "Usage: http_server <address> <port> <threads> <doc_root>\n";
	//		std::cerr << "  For IPv4, try:\n";
	//		std::cerr << "    receiver 0.0.0.0 80 1 .\n";
	//		std::cerr << "  For IPv6, try:\n";
	//		std::cerr << "    receiver 0::0 80 1 .\n";
	//		return 1;
	//	}

	//	// Initialise the server.
	//	std::size_t num_threads = boost::lexical_cast<std::size_t>(argv[3]);
	//	http::server3::server s(argv[1], argv[2], argv[4], num_threads);

	//	// Run the server until stopped.
	//	s.run();
	//}
	//catch (std::exception& e)
	//{
	//	std::cerr << "exception: " << e.what() << "\n";
	//}
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