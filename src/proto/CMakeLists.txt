CMAKE_MINIMUM_REQUIRED(VERSION 2.8.5)

FIND_PACKAGE(Protobuf REQUIRED)
INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIRS})

SET(ProtoFiles
        battle.proto
        bullet.proto
        engine.proto
        init.proto
        serivce.proto
        weapon.proto)

SET(RPCFiles
        serivce.proto)

function(GRPC_GENERATE_CPP SRCS HDRS)
    if (NOT ARGN)
        message(SEND_ERROR "Error: GRPC_GENERATE_CPP() called without any proto files")
        return()
    endif ()

    if (PROTOBUF_GENERATE_CPP_APPEND_PATH)
        # Create an include path for each file specified
        foreach (FIL ${ARGN})
            get_filename_component(ABS_FIL ${FIL} ABSOLUTE)
            get_filename_component(ABS_PATH ${ABS_FIL} PATH)
            list(FIND _protobuf_include_path ${ABS_PATH} _contains_already)
            if (${_contains_already} EQUAL -1)
                list(APPEND _protobuf_include_path -I ${ABS_PATH})
            endif ()
        endforeach ()
    else ()
        set(_protobuf_include_path -I ${CMAKE_CURRENT_SOURCE_DIR})
    endif ()

    if (DEFINED PROTOBUF_IMPORT_DIRS)
        foreach (DIR ${PROTOBUF_IMPORT_DIRS})
            get_filename_component(ABS_PATH ${DIR} ABSOLUTE)
            list(FIND _protobuf_include_path ${ABS_PATH} _contains_already)
            if (${_contains_already} EQUAL -1)
                list(APPEND _protobuf_include_path -I ${ABS_PATH})
            endif ()
        endforeach ()
    endif ()

    set(${SRCS})
    set(${HDRS})
    foreach (FIL ${ARGN})
        get_filename_component(ABS_FIL ${FIL} ABSOLUTE)
        get_filename_component(FIL_WE ${FIL} NAME_WE)

        list(APPEND ${SRCS} "${CMAKE_CURRENT_BINARY_DIR}/${FIL_WE}.grpc.pb.cc")
        list(APPEND ${HDRS} "${CMAKE_CURRENT_BINARY_DIR}/${FIL_WE}.grpc.pb.h")

        add_custom_command(
                OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${FIL_WE}.grpc.pb.cc"
                "${CMAKE_CURRENT_BINARY_DIR}/${FIL_WE}.grpc.pb.h"
                COMMAND ${PROTOBUF_PROTOC_EXECUTABLE}
                ARGS "--proto_path=${CMAKE_CURRENT_SOURCE_DIR}"
                "--grpc_out=${CMAKE_CURRENT_BINARY_DIR}"
                "--plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin"
                "${ABS_FIL}"
                DEPENDS ${ABS_FIL} ${PROTOBUF_PROTOC_EXECUTABLE}
                COMMENT "Running C++ grpc compiler on ${FIL}"
                VERBATIM)
    endforeach ()

    set_source_files_properties(${${SRCS}} ${${HDRS}} PROPERTIES GENERATED TRUE)
    set(${SRCS} ${${SRCS}} PARENT_SCOPE)
    set(${HDRS} ${${HDRS}} PARENT_SCOPE)
endfunction()

PROTOBUF_GENERATE_CPP(ProtoSources ProtoHeaders ${ProtoFiles})
GRPC_GENERATE_CPP(GRPCSources GRPCHeaders ${RPCFiles})
ADD_LIBRARY(proto STATIC ${ProtoSources} ${ProtoHeaders} ${GRPCSources} ${GRPCHeaders})
TARGET_LINK_LIBRARIES(proto ${PROTOBUF_LIBRARIES} grpc++)