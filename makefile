OBJS	= main.o commands.o curiosity.o util.o cargar.o agregar.o ayuda.o guardar.o
SOURCE	= src/main.cxx src/curiosity/commands/commands.cxx src/robot/curiosity.cxx src/util/util.cxx src/curiosity/commands/cargar.cxx src/curiosity/commands/agregar.cxx src/curiosity/commands/ayuda.cxx src/curiosity/commands/guardar.cxx
HEADER	= src/curiosity/commands/commands.h src/robot/curiosity.h src/util/util.h src/curiosity/commands/cargar.h src/curiosity/commands/agregar.h src/curiosity/commands/ayuda.h src/curiosity/commands/guardar.h
OUT		= main
CC		= g++
FLAGS	= -std=c++11 -g -c -Wall
LFLAGS	= 

main: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)
main.o: src/main.cxx
	$(CC) $(FLAGS) src/main.cxx 

commands.o: src/curiosity/commands/commands.cxx
	$(CC) $(FLAGS) src/curiosity/commands/commands.cxx 

curiosity.o: src/curiosity/curiosity.cxx
	$(CC) $(FLAGS) src/curiosity/curiosity.cxx 

util.o: src/util/util.cxx
	$(CC) $(FLAGS) src/util/util.cxx 

cargar.o: src/curiosity/commands/cargar.cxx
	$(CC) $(FLAGS) src/curiosity/commands/cargar.cxx 

agregar.o: src/curiosity/commands/agregar.cxx
	$(CC) $(FLAGS) src/curiosity/commands/agregar.cxx 

ayuda.o: src/curiosity/commands/ayuda.cxx
	$(CC) $(FLAGS) src/curiosity/commands/ayuda.cxx 

guardar.o: src/curiosity/commands/guardar.cxx
	$(CC) $(FLAGS) src/curiosity/commands/guardar.cxx 


clean:
	rm -f $(OBJS) $(OUT)
