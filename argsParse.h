#ifndef ARGSPARSE_H_
#define ARGSPARSE_H_

//  正确的参数命令：
//  ./a.out :   可执行程序的名字
//  ./a.out -l  :   查看总CPU的使用率（默认的命令为./a.out）
//  ./a.out -f pid  :   查看某个进程的CPU使用率
//  ./a.out -p tid  :   查看某个线程的CPU使用率
//  ./a.out [-lfp] [long] [[-ifp] [long] ... ]

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
        void getNextId(long &id);
        int getStatus(int i);
        int getStatusNum() {
            return _status.size();
        }
        bool exit() {
            return _exit == 0;
        }
    private:
        std::vector<int> _status;
        std::vector<long> _id;
        int _next;                      // 和_id配合使用
        int _exit;
        int _argc;
        char **_argv;
    };
}

#endif