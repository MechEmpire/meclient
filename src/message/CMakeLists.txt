CMAKE_MINIMUM_REQUIRED(VERSION 2.8.5)

FIND_PACKAGE(Protobuf REQUIRED)
INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

SET(ProtoFiles
        bullet.proto
        engine.proto
        message.proto
        weapon.proto)

PROTOBUF_GENERATE_CPP(ProtoSources ProtoHeaders ${ProtoFiles})
ADD_LIBRARY(message STATIC ${ProtoSources} ${ProtoHeaders})
TARGET_LINK_LIBRARIES(message ${PROTOBUF_LIBRARIES})