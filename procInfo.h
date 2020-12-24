#ifndef PROCINFO_H_
#define PROCINFO_H_

#include <stdlib.h>

#include "./procStat.h"

namespace durian
{
    class ProcInfo
    {
    public:
        ProcInfo();
        ~ProcInfo() = default;
        void test() {
            _stat.test();
        }
    private:
        ProcStat _stat;
    };
}

#endif