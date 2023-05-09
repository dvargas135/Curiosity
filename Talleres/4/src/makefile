OBJS   = main.o airport.o
SOURCE = main.cxx airport.cxx
HEADER = airport.h
OUT = main
CC = g++
FLAGS = -std=c++11 -g -c -Wall
LFLAGS = 

$(OUT): $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)
main.o: main.cxx
	$(CC) $(FLAGS) main.cxx -o main.o

airport.o: airport.cxx
	$(CC) $(FLAGS) airport.cxx -o airport.o


clean:
ifeq ($(OS), Windows_NT)
	del /Q *.o $(OUT).exe
else
	rm -f $(OBJS) $(OUT)
endif