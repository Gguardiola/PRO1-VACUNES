OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

all: main.exe

main.exe: main.o Cambra.o Control.o 
	g++ -o main.exe main.o Cambra.o Control.o
		
main.o: main.cpp Cambra.hpp Control.hpp 
	g++ -c main.cpp $(OPCIONS)
	
Cambra.o: Cambra.cpp Cambra.hpp
	g++ -c Cambra.cpp $(OPCIONS)

Control.o: Control.cpp Control.hpp Cambra.hpp arbreBin.hpp
	g++ -c Control.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
