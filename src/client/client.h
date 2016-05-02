//
// Created by jcy on 5/1/16.
//

#ifndef MECLIENT_CLIENT_H
#define MECLIENT_CLIENT_H

#include <cstdint>
#include <string>
#include <boost/asio.hpp>

class client {
    using namespace boost::asio::ip;
    using resolver_type = udp::resolver;
    using io_service_type = boost::asio::io_service;
public:
    client(std::string address, std::string port);


private:
    io_service_type io_service;
    resolver_type resolver;
};


#endif //MECLIENT_CLIENT_H
