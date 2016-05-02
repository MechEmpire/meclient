//
// Created by jcy on 5/1/16.
//

#include <boost/asio.hpp>
#include "client.h"

client::client(std::string address, std::string port) : resolver(io_service) {
    udp::resolver::query query(address, port);
}