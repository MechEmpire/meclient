CMAKE_MINIMUM_REQUIRED(VERSION 2.8.5)
PROJECT(meclient)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)