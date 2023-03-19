OBJS	= main.o command.o curiosity.o system.o util.o cargar.o ayuda.o agregar.o element.o guardar.o simular_comandos.o
SOURCE	= main.cxx classes/command.cxx classes/curiosity.cxx classes/system.cxx util/util.cxx commands/cargar.cxx commands/ayuda.cxx commands/agregar.cxx classes/element.cxx commands/guardar.cxx commands/simular_comandos.cxx
HEADER	=       classes/command.hpp classes/curiosity.hpp classes/system.hpp util/util.hpp commands/cargar.hpp commands/ayuda.hpp commands/agregar.hpp classes/element.hpp commands/guardar.hpp commands/simular_comandos.hpp
OUT		= main
CC		= g++
FLAGS	= -std=c++11 -g -c -Wall
LFLAGS	= 

main: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)
main.o: main.cxx
	$(CC) $(FLAGS) main.cxx 

command.o: classes/command.cxx
	$(CC) $(FLAGS) classes/command.cxx 

curiosity.o: classes/curiosity.cxx
	$(CC) $(FLAGS) classes/curiosity.cxx 

system.o: classes/system.cxx
	$(CC) $(FLAGS) classes/system.cxx 

util.o: util/util.cxx
	$(CC) $(FLAGS) util/util.cxx 

cargar.o: commands/cargar.cxx
	$(CC) $(FLAGS) commands/cargar.cxx 

ayuda.o: commands/ayuda.cxx
	$(CC) $(FLAGS) commands/ayuda.cxx 

agregar.o: commands/agregar.cxx
	$(CC) $(FLAGS) commands/agregar.cxx 

element.o: classes/element.cxx
	$(CC) $(FLAGS) classes/element.cxx 

guardar.o: commands/guardar.cxx
	$(CC) $(FLAGS) commands/guardar.cxx 

simular_comandos.o: commands/simular_comandos.cxx
	$(CC) $(FLAGS) commands/simular_comandos.cxx 


clean:
	rm -f $(OBJS) $(OUT)
