CMAKE_MINIMUM_REQUIRED(VERSION 2.8.5)

SET(INTEGRATE_HEADER_FILES
        AI.h
        Robot.h Weapon.h)

SET(INTEGRATE_SOURCE_FILES
        AI.cpp
        Robot.cpp)

ADD_LIBRARY(integrate
        ${INTEGRATE_HEADER_FILES}
        ${INTEGRATE_SOURCE_FILES}
        Engine.h)