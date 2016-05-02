//
// Created by jcy on 5/1/16.
//

#include <boost/asio.hpp>
#include <iostream>
#include "client.h"

using std::cout;

client::client(std::string address, unsigned short port) {
    using namespace boost::asio::ip;
    socket_ptr_.reset(new udp::socket(io_service_, udp::endpoint(address_v4().from_string(address), port)));
    if (!socket_ptr_->available()) {
        throw std::runtime_error("udp connect error");
    }
}