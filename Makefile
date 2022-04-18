all:compile link                                                                           
compile:                                                                                   
	g++ -I src/include -c Config.cpp Inventory.cpp main.cpp                                              
link:                                                                                      
	g++ main.o -o main -L /usr/include/SFML -l sfml-graphics -l sfml-window -l sfml-system Config.cpp Inventory.cpp
go:
	./main