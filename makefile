test : main.o argsParse.o procInfo.o procStat.o cpu.o
	g++ -o test main.o argsParse.o procInfo.o procStat.o cpu.o

main.o : main.cc argsParse.h procInfo.o cpu.h
	g++ -c main.cc
argsParse.o : argsParse.cc argsParse.h
	g++ -c argsParse.cc
procInfo.o : procInfo.cc procInfo.h procStat.h
	g++ -c procInfo.cc
procStat.o : procStat.cc procStat.h
	g++ -c procStat.cc

cpu.o : cpu.cc cpu.h procInfo.h
	g++ -c cpu.cc

clean:
	rm *.o