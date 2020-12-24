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
        // 读取文件的第一行
        std::string buf;
        std::getline(_in, buf);
        std::istringstream str(buf);
        std::string p;
        str >> p;
        for(int i = 0; i < 10; ++i) {
            str >> _stat[i];
        }
    }
    void ProcStat::calculate(ulong &ans) {
        int i = 0;
        while(i < 10) {
            ans += _stat[i];
            ++i;
        }
    }
    ulong ProcStat::getidle(int &idle) {
        return _stat[idle];
    }
}