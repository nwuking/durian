#include "./argsParse.h"
#include "./procInfo.h"
#include "./cpu.h"

#include <iostream>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) 
{
    durian::ArgsParse obj(argc, argv);
    obj.parse();
    if(obj.exit()) {
        std::cout << "命令行参数不符合格式！" << std::endl;
        ::exit(0);
    }
    durian::ProcInfo s1;
    ::sleep(1);                                            //  根据需要，自由调整睡眠时间，使两个快照时间间隔尽可能小
    durian::ProcInfo s2;
    durian::Cpu cal(s1, s2);
    cal.cpuAll();
    return 0;
}