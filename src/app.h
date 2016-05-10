//
// Created by jcy on 5/2/16.
//

#ifndef MECLIENT_APP_H
#define MECLIENT_APP_H

#include "argument/argument.h"
#include "integrate/AI.h"
#include "integrate/Robot.h"
#include "proto/serivce.grpc.pb.h"

class app {
public:
    app(int argc, const char *argv[]);

    int exec();

private:
    bool init();

private:
    argument argument_;
    std::unique_ptr<AI> ai_;
    Robot robot_;
    std::unique_ptr<MESerivce::Stub> stub_ptr_;
};


#endif //MECLIENT_APP_H
