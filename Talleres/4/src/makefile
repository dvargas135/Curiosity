OBJS   = main.o airport.o edge.o flight.o graphadjacencylistprice.o node.o util.o
SOURCE = main.cxx Airport.cxx Edge.cxx Flight.cxx GraphAdjacencyListPrice.cxx Node.cxx Util.cxx
HEADER = Airport.hpp Csv.hpp Edge.hpp Flight.hpp GraphAdjacencyListPrice.hpp Node.hpp Util.hpp
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

graphadjacencylistprice.o: GraphAdjacencyListPrice.cxx
	$(CC) $(FLAGS) GraphAdjacencyListPrice.cxx -o GraphAdjacencyListPrice.o

node.o: Node.cxx
	$(CC) $(FLAGS) Node.cxx -o Node.o

util.o: Util.cxx
	$(CC) $(FLAGS) Util.cxx -o Util.o


clean:
ifeq ($(OS), Windows_NT)
	del /Q *.o $(OUT).exe
else
	rm -f $(OBJS) $(OUT)
endif