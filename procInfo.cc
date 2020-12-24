#include "./procInfo.h"

namespace durian
{
    ProcInfo::ProcInfo() 
        :   _stat()
    {
        _stat.getData();
    }
}