//
// Created by jcy on 5/11/16.
//


#include <gtest/gtest.h>
#include "../../src/argument/argument.h"

TEST(argument_test, test_no_arg) {
    const char *argv[] = {};
    argument arg(1, argv);
    EXPECT_FALSE(arg.is_inited());
    EXPECT_STREQ("", arg.get_address().c_str());
    EXPECT_STREQ("", arg.get_port().c_str());
    EXPECT_STREQ(":", arg.get_channel().c_str());
}

TEST(argument_test, test_help_arg) {
    const char *argv[] = {
            "..."
                    "-h"
    };
    argument arg(1, argv);
    EXPECT_FALSE(arg.is_inited());
    EXPECT_STREQ("", arg.get_address().c_str());
    EXPECT_STREQ("", arg.get_port().c_str());
    EXPECT_STREQ(":", arg.get_channel().c_str());
}

TEST(argument_test, test_only_port_arg) {
    const char *argv[] = {
            "...",
            "-p",
            "1234"
    };
    argument arg(3, argv);
    EXPECT_TRUE(arg.is_inited());
    EXPECT_STREQ("127.0.0.1", arg.get_address().c_str());
    EXPECT_STREQ("1234", arg.get_port().c_str());
    EXPECT_STREQ("127.0.0.1:1234", arg.get_channel().c_str());
}

TEST(argument_test, test_port_and_address_arg) {
    const char *argv[] = {
            "...",
            "-a",
            "192.168.0.10",
            "-p",
            "1234"
    };
    argument arg(5, argv);
    EXPECT_TRUE(arg.is_inited());
    EXPECT_STREQ("192.168.0.10", arg.get_address().c_str());
    EXPECT_STREQ("1234", arg.get_port().c_str());
    EXPECT_STREQ("192.168.0.10:1234", arg.get_channel().c_str());
}
