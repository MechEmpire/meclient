//
// Created by jcy on 5/2/16.
//

#ifndef MECLIENT_APP_H
#define MECLIENT_APP_H

#include "argument/argument.h"

class app {
public:
    app(int argc, const char *argv[]);

    int exec();

private:
    argument argument_;
};


#endif //MECLIENT_APP_H
