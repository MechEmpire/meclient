CMAKE_MINIMUM_REQUIRED(VERSION 2.8.5)

FIND_PACKAGE(Protobuf REQUIRED)
INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIRS})
INCLUDE(grpc_func.cmake)

SET(ProtoFiles
        battle.proto
        bullet.proto
        engine.proto
        init.proto
        location.proto
        serivce.proto
        weapon.proto)

SET(RPCFiles
        serivce.proto)

PROTOBUF_GENERATE_CPP(ProtoSources ProtoHeaders ${ProtoFiles})
GRPC_GENERATE_CPP(GRPCSources GRPCHeaders ${RPCFiles})
ADD_LIBRARY(proto STATIC ${ProtoSources} ${ProtoHeaders} ${GRPCSources} ${GRPCHeaders})
TARGET_LINK_LIBRARIES(proto ${PROTOBUF_LIBRARIES} grpc++)