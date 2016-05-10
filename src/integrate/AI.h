//
// Created by jcy on 5/7/16.
//

#ifndef MECLIENT_AI_H
#define MECLIENT_AI_H


#include "Robot.h"

class AI {
public:
    AI(Robot &robot);

    void update();

private:
    Robot &robot_;
};


#endif //MECLIENT_AI_H
