//
// Created by jcy on 5/1/16.
//

#ifndef MECLIENT_CLIENT_H
#define MECLIENT_CLIENT_H

#include <cstdint>
#include <string>
#include <memory>
#include <boost/asio.hpp>

class client {
    using socket_type = boost::asio::ip::udp::socket;
    using io_service_type = boost::asio::io_service;
    using unique_socket_ptr = std::unique_ptr<socket_type>;
public:
    client(std::string address, unsigned short port);

//  void send()

//  void receive()

private:
    io_service_type io_service_;
    unique_socket_ptr socket_ptr_;
};


#endif //MECLIENT_CLIENT_H
