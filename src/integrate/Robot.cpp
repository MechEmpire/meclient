//
// Created by jcy on 5/7/16.
//

#include "Robot.h"

Robot::Robot() :
        is_inited(false) {

}

void Robot::init_lock() {
    is_inited = true;
}

void Robot::set_engine(const Engine &engine) {
    if (!is_inited)
        engine_ = engine;
}

const Engine &Robot::get_engine() {
    return engine_;
}

void Robot::set_weapon(const Weapon &weapon) {
    if (!is_inited)
        weapon_ = weapon;
}

const Weapon &Robot::get_weapon() {
    return weapon_;
}

void Robot::set_id(int id) {
    id_ = id;
}

int Robot::get_id() {
    return id_;
}
