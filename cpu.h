#ifndef CPU_H_
#define CPU_H_

// 接收两个ProcInfo Obj
// 打印CPU的使用率

#include <iostream>

#include "./procInfo.h"

namespace durian
{
    class Cpu
    {
    public:
        Cpu(ProcInfo &s1, ProcInfo &s2) : _s1(s1), _s2(s2), _active1(0), _idle1(0),
                                          _active2(0), _idle2(0) {}
        ~Cpu() = default;
        void cpuAll();
        void cpuProcess();
        void cpuThread();
    private:
        ProcInfo &_s1;
        ProcInfo &_s2;
        ulong _active1;
        ulong _idle1;
        ulong _active2;
        ulong _idle2;
    };
}

#endif