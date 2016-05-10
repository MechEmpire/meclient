//
// Created by jcy on 5/2/16.
//

#include "app.h"
#include <grpc++/grpc++.h>

app::app(int argc, const char *argv[]) : argument_(argc, argv) {
    stub_ptr_ = MESerivce::NewStub(
            grpc::CreateChannel(argument_.get_channel(), grpc::InsecureChannelCredentials())
    );

    ai_.reset(new AI(robot_));
    robot_.init_lock();
    init();
}

int app::exec() {
//    InitSerice
    for (; ;) {
        BattleRequest request;
        grpc::ClientContext context;
        BattleReply reply;

        ai_->update();

        //input robot info to request

        if (stub_ptr_->MEBattle(&context, request, &reply).ok()) {
//            robot_.set_id(reply.robotid());
//            return true;/
        } else {
//            return false;
        }

    }
    return 0;
}

bool app::init() {
    InitRequest request;

    request.set_engine(static_cast<Engine_Type >(robot_.get_engine()));
    request.set_weapon(static_cast<Weapon_Type >(robot_.get_weapon()));

    InitReply reply;
    grpc::ClientContext context;

    if (stub_ptr_->MEInit(&context, request, &reply).ok()) {
        robot_.set_id(reply.robotid());
        return true;
    } else {
        return false;
    }
}

