OBJS   = obj/main.o obj/command.o obj/curiosity.o obj/element.o obj/system.o obj/vector.o obj/agregar.o obj/ayuda.o obj/cargar.o obj/guardar.o obj/simular_comandos.o obj/ubicar_elementos.o obj/util.o obj/point.o obj/quadnode.o obj/quadtree.o obj/en_cuadrante.o
SOURCE = main.cxx classes/command.cxx classes/curiosity.cxx classes/element.cxx classes/system.cxx classes/vector.cxx commands/agregar.cxx commands/ayuda.cxx commands/cargar.cxx commands/guardar.cxx commands/simular_comandos.cxx commands/ubicar_elementos.cxx util/util.cxx trees/quad/point.cxx trees/quad/quadnode.cxx trees/quad/quadtree.cxx commands/en_cuadrante.cxx
HEADER = classes/command.hpp classes/curiosity.hpp classes/element.hpp classes/system.hpp classes/vector.hpp commands/agregar.hpp commands/ayuda.hpp commands/cargar.hpp commands/guardar.hpp commands/simular_comandos.hpp commands/ubicar_elementos.hpp util/util.hpp trees/quad/point.hpp trees/quad/quadnode.hpp trees/quad/quadtree.hpp commands/en_cuadrante.hpp
OUT = main
CC = g++
FLAGS = -std=c++11 -g -c -Wall
LFLAGS = 

$(OUT): $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)
obj/main.o: main.cxx
	$(CC) $(FLAGS) main.cxx -o obj/main.o

obj/command.o: classes/command.cxx
	$(CC) $(FLAGS) classes/command.cxx -o obj/command.o

obj/curiosity.o: classes/curiosity.cxx
	$(CC) $(FLAGS) classes/curiosity.cxx -o obj/curiosity.o

obj/element.o: classes/element.cxx
	$(CC) $(FLAGS) classes/element.cxx -o obj/element.o

obj/system.o: classes/system.cxx
	$(CC) $(FLAGS) classes/system.cxx -o obj/system.o

obj/vector.o: classes/vector.cxx
	$(CC) $(FLAGS) classes/vector.cxx -o obj/vector.o

obj/agregar.o: commands/agregar.cxx
	$(CC) $(FLAGS) commands/agregar.cxx -o obj/agregar.o

obj/ayuda.o: commands/ayuda.cxx
	$(CC) $(FLAGS) commands/ayuda.cxx -o obj/ayuda.o

obj/cargar.o: commands/cargar.cxx
	$(CC) $(FLAGS) commands/cargar.cxx -o obj/cargar.o

obj/guardar.o: commands/guardar.cxx
	$(CC) $(FLAGS) commands/guardar.cxx -o obj/guardar.o

obj/simular_comandos.o: commands/simular_comandos.cxx
	$(CC) $(FLAGS) commands/simular_comandos.cxx -o obj/simular_comandos.o

obj/ubicar_elementos.o: commands/ubicar_elementos.cxx
	$(CC) $(FLAGS) commands/ubicar_elementos.cxx -o obj/ubicar_elementos.o

obj/util.o: util/util.cxx
	$(CC) $(FLAGS) util/util.cxx -o obj/util.o

#new classes added for component ii
obj/point.o: trees/quad/point.cxx
	$(CC) $(FLAGS) trees/quad/point.cxx -o obj/point.o

obj/quadnode.o: trees/quad/quadnode.cxx
	$(CC) $(FLAGS) trees/quad/quadnode.cxx -o obj/quadnode.o

obj/quadtree.o: trees/quad/quadtree.cxx
	$(CC) $(FLAGS) trees/quad/quadtree.cxx -o obj/quadtree.o

obj/en_cuadrante.o: commands/en_cuadrante.cxx
	$(CC) $(FLAGS) commands/en_cuadrante.cxx -o obj/en_cuadrante.o

clean:
ifeq ($(OS), Windows_NT)
	del /Q obj\*.o $(OUT).exe
else
	rm -f $(OBJS) $(OUT)
endif