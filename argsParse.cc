#include "./argsParse.h"

namespace durian
{
    ArgsParse::ArgsParse(int argc, char **argv) 
        : _exit(1),
          _argc(argc),
          _argv(argv)
    {}
    void ArgsParse::parse() {
        if(_argc != 1) {
            _exit = 0;
        }
    }
}