//
// Created by jcy on 5/2/16.
//

#ifndef MECLIENT_ARGUMENT_H
#define MECLIENT_ARGUMENT_H

#include <string>
#include <boost/program_options/variables_map.hpp>

class argument {
public:
    argument(int argc, const char *argv[]);

    const std::string &get_address() const;

    unsigned short get_port() const;

private:
    void config_address(const boost::program_options::variables_map &variables_map);

    void config_port(const boost::program_options::variables_map &variables_map);

private:
    std::string address_;
    unsigned short port_;
};


#endif //MECLIENT_ARGUMENT_H
