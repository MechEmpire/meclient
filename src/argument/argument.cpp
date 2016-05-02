//
// Created by jcy on 5/2/16..
//

#include "argument.h"
#include <boost/program_options.hpp>
#include <iostream>

namespace po = boost::program_options;
using std::string;
using std::cout;

argument::argument(int argc, const char *argv[]) {
    po::options_description description("Allowed options");
    description.add_options()
            ("help,h", "produce help message")
            ("address,a", po::value<string>(), "set server address")
            ("port,p", po::value<ushort>(), "set server port");

    po::variables_map variables_map;
    po::store(po::parse_command_line<char>(argc, argv, description), variables_map);
    po::notify(variables_map);

    if (variables_map.count("help")) {
        cout << description << "\n";
    } else {
        config_address(variables_map);
        config_port(variables_map);
    }
}

void argument::config_port(const boost::program_options::variables_map &variables_map) {
    if (variables_map.count("port")) {
        port_ = variables_map["port"].as<ushort>();
        cout << "Port is " << port_ << ".\n";
    } else {
        cout << "Please input the port or the program will never run!\n";
    }
}

void argument::config_address(const boost::program_options::variables_map &variables_map) {
    if (variables_map.count("address")) {
        address_ = variables_map["address"].as<string>();
        cout << "Address is " << address_ << ".\n";
    } else {
        address_ = "127.0.0.1";
        cout << "The address will be set to " << address_ << " by default.\n";
    }
}

const string &argument::get_address() const {
    return address_;
}

unsigned short argument::get_port() const {
    return port_;
}
