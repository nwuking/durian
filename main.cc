#include "./argsParse.h"
#include "./procInfo.h"

#include <iostream>
#include <string.h>

int main(int argc, char **argv) 
{
    durian::ArgsParse obj(argc, argv);
    obj.parse();
    if(obj.exit()) {
        std::cout << "命令行参数不符合格式！" << std::endl;
        ::exit(0);
    }
    durian::ProcInfo s1;
    s1.test();
    return 0;
}