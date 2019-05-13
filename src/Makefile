CXX = g++
LIBS = -laria2
DIR_INC = ./include

TencentComic: main.o Download.o Readfile.o Regular.o
	$(CXX) $(LIBS) $^ -o $@

main.o : main.cpp
	$(CXX) -I $(DIR_INC) -c $^
	
Download.o : Download.cpp
	$(CXX) -I $(DIR_INC) -c $^

Readfile.o : Readfile.cpp
	$(CXX) -I $(DIR_INC) -c $^
	
Regular.o : Regular.cpp
	$(CXX) -I $(DIR_INC) -c $^

.PHONY:clean
clean:
	-rm main.o Download.o Readfile.o Regular.o


