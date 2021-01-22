#ifndef ARGSPARSE_H_
#define ARGSPARSE_H_

//  正确的参数命令：
//  ./a.out :   可执行程序的名字
//  ./a.out :   查看总CPU的使用率

#include <string.h>
#include <vector>
#include <stdlib.h>

namespace durian
{
    class ArgsParse
    {
    public:
        ArgsParse(int argc, char **argv);
        ~ArgsParse() = default;
        void parse() ;
        bool exit() {
            return _exit == 0;
        }
    private:
        int _exit;
        int _argc;
        char **_argv;
    };
}

#endif