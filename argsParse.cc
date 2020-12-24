#include "./argsParse.h"

namespace durian
{
    ArgsParse::ArgsParse(int argc, char **argv) 
        : _exit(1),
          _next(0),
          _argc(argc),
          _argv(argv)
    {}
    void ArgsParse::getNextId(long &id) {
        // 获取process or thread 的id
        id = _id[_next];
        ++_next;
    }
    int ArgsParse::getStatus(int m) {
        // 获取status
        // 用于查看总CPU or process CPU or  thread CPU
        return _status[m];
    }
    void ArgsParse::parse() {
        if(_argc == 1) {
            // 只有./a.out,默认查看总CPU的使用率
            _status.emplace_back(1);
        }
        else {
            // 有多个options
            int m = 1;
            while(m < _argc) {
                if(::strlen(_argv[m]) != 2) {
                    _exit = 0;
                    break;
                }
                else {
                    if(_argv[m][0] != '-') {
                        _exit = 0;
                        break;
                    }
                    if(_argv[m][1] == 'l') {
                        // 查看CPU总使用率
                        _status.emplace_back(1);
                        // 不用关心下一个argv
                    }
                    else if(_argv[m][1] == 'f') {
                        // 查看某一进程的CPU使用率
                        _status.emplace_back(2);
                        ++m;
                        if(m == _argc) {
                            _exit = 0;
                            break;
                        }
                        long p = ::atoi(_argv[m]);
                        _id.emplace_back(p);
                    }
                    else if(_argv[m][1] == 'p') {
                        // 查看某线程的CPU使用率
                        _status.emplace_back(3);
                        ++m;
                        if(m == _argc) {
                            _exit = 0;
                            break;
                        }
                        long p = ::atoi(_argv[m]);
                        _id.emplace_back(p);
                    }
                    else {
                        _exit = 0;
                        break;
                    }
                }
                ++m;
            }
        }
    }
}