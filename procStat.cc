#include "./procStat.h"

#include <sstream>

namespace durian
{
    typedef ProcStat::ulong ulong;
    ProcStat::ProcStat() : _in() {
        // 读取 /proc/stat 文件
        _in.open(durian::pathName);
    }
    ProcStat::~ProcStat() {
        _in.close();
    }
    void ProcStat::getData() {
        // 读取文件的第一行，第一行为总CPU的使用情况
        std::string buf;
        std::getline(_in, buf);
        std::istringstream str(buf);
        std::string p;
        str >> p;
        for(int i = 0; i < 10; ++i) {
            str >> _stat[i];
        }
    }
    void ProcStat::getActive(ulong &ans) {
        // CPU 活动的时间
        ans = _stat[_user] + _stat[_nice] + _stat[_system] + 
              _stat[_irq] + _stat[_sfotirq] + _stat[_steal] +
              _stat[_guest] + _stat[_guest_nice];
    }
    void ProcStat::getidle(ulong &ans) {
        // CPU 休闲的时间
        ans = _stat[_idle] + _stat[_iowait];
    }
}