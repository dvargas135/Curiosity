OBJS   = main.o airport.o edge.o flight.o node.o util.o graphadjacencylist.o
SOURCE = main.cxx Airport.cxx Edge.cxx Flight.cxx Node.cxx Util.cxx GraphAdjacencyList.cxx
HEADER = Airport.hpp Csv.hpp Edge.hpp Flight.hpp Node.hpp Util.hpp GraphAdjacencyList.hpp
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

edge.o: Edge.cxx
	$(CC) $(FLAGS) Edge.cxx -o Edge.o

flight.o: Flight.cxx
	$(CC) $(FLAGS) Flight.cxx -o Flight.o

node.o: Node.cxx
	$(CC) $(FLAGS) Node.cxx -o Node.o

util.o: Util.cxx
	$(CC) $(FLAGS) Util.cxx -o Util.o

graphadjacencylist.o: GraphAdjacencyList.cxx
	$(CC) $(FLAGS) GraphAdjacencyList.cxx -o GraphAdjacencyList.o
	

clean:
ifeq ($(OS), Windows_NT)
	del /Q *.o $(OUT).exe
else
	rm -f $(OBJS) $(OUT)
endif