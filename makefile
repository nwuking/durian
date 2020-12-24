test : main.o argsParse.o procInfo.o procStat.o
	g++ -o test main.o argsParse.o procInfo.o procStat.o

main.o : main.cc argsParse.h procInfo.o
	g++ -c main.cc
argsParse.o : argsParse.cc argsParse.h
	g++ -c argsParse.cc
procInfo.o : procInfo.cc procInfo.h procStat.h
	g++ -c procInfo.cc
procStat.o : procStat.cc procStat.h
	g++ -c procStat.cc

clean:
	rm *.o