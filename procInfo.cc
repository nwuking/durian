#include "./procInfo.h"

namespace durian
{
    ProcInfo::ProcInfo() 
        :   _stat()
    {
        _stat.getData();
    }
    void ProcInfo::cpuAll(ulong &active, ulong &idle) {
        _stat.getActive(active);
        _stat.getidle(idle);
    }
}