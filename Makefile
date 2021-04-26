OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

all: main.exe

main.exe: main.o Nevera.o Control.o 
	g++ -o main.exe main.o Nevera.o Control.o
		
main.o: main.cpp Nevera.hpp Control.hpp
	g++ -c main.cpp $(OPCIONS)
	
Nevera.o: Nevera.cpp Nevera.hpp
	g++ -c Nevera.cpp $(OPCIONS)

Control.o: Control.cpp Control.hpp Nevera.hpp
	g++ -c Control.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
