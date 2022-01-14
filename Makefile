all: compile link
compile:
	g++ -I src/include -c Config.cpp main.cpp
link:
	g++ main.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system Config.cpp
clean:
	rm -f *.exe *.o
go: 
	main