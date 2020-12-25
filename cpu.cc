#include "./cpu.h"

namespace durian
{
    void Cpu::cpuAll() {
        _s1.cpuAll(_active1, _idle1);
        _s2.cpuAll(_active2, _idle2);
        float activeTotal = static_cast<float>(_active2 - _active1);
        float idleTotal = static_cast<float>(_idle2 - _idle1);
        float totalTime = (activeTotal + idleTotal);
        if(totalTime == 0.0) {
            std::cout << "CPU: 0.00%" << std::endl; 
        }
        else 
            std::cout << "CPU: " << std::cout.precision(3) << 100.00 * (activeTotal / totalTime) << "%" << std::endl;
    }
}