//
// Created by jcy on 5/7/16.
//

#ifndef MECLIENT_ROBOT_H
#define MECLIENT_ROBOT_H

#include "Engine.h"
#include "Weapon.h"

class Robot {
    friend class app;

public:
    Robot();

    void set_engine(const Engine &engine);

    const Engine &get_engine();

    void set_weapon(const Weapon &weapon);

    const Weapon &get_weapon();

    int get_id();
    //
    // set arguments
    //

private:
    void init_lock();

    void set_id(int id);

private:
    bool is_inited;
    Engine engine_;
    Weapon weapon_;
    int id_;
};


#endif //MECLIENT_ROBOT_H
