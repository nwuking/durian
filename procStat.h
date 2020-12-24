#ifndef PROCSTAT_H_
#define PROCSTAT_H_

// 读取 /proc/stat 文件
// 计算总CPU的使用率

#include <string>
#include <array>
#include <fstream>
#include <iostream>

namespace durian
{
    static std::string pathName("/proc/stat");
    class ProcStat 
    {
    public:
        typedef unsigned long ulong;
        ProcStat();
        ~ProcStat();
        void getData();
        void calculate(ulong &ans);
        ulong getidle(int &idle);
        void test() {
            for(int i = 0; i < 10; ++i) {
                std::cout << _stat[i] << std::endl;
            }
        }
    private:
        std::array<ulong, 10> _stat;
        std::ifstream _in;
    };
}

#endif