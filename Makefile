all:compile link                                                                           
compile:                                                                                   
	g++ -I src/include -c config.cpp Inventory.cpp main.cpp                                              
link:                                                                                      
	g++ main.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system Config.cpp Inventory.cpp
go:
	main