OBJS	= main.o command.o curiosity.o system.o util.o cargar.o ayuda.o agregar.o element.o guardar.o simular_comandos.o
SOURCE	= main.cxx command.cxx curiosity.cxx system.cxx util.cxx cargar.cxx ayuda.cxx agregar.cxx element.cxx guardar.cxx simular_comandos.cxx
HEADER	= command.h curiosity.h system.h util.h cargar.h ayuda.h agregar.h element.h guardar.h simular_comandos.h
OUT		= main
CC		= g++
FLAGS	= -std=c++11 -g -c -Wall
LFLAGS	= 

main: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)
main.o: main.cxx
	$(CC) $(FLAGS) main.cxx 

command.o: command.cxx
	$(CC) $(FLAGS) command.cxx 

curiosity.o: curiosity.cxx
	$(CC) $(FLAGS) curiosity.cxx 

system.o: system.cxx
	$(CC) $(FLAGS) system.cxx 

util.o: util.cxx
	$(CC) $(FLAGS) util.cxx 

cargar.o: cargar.cxx
	$(CC) $(FLAGS) cargar.cxx 

ayuda.o: ayuda.cxx
	$(CC) $(FLAGS) ayuda.cxx 

agregar.o: agregar.cxx
	$(CC) $(FLAGS) agregar.cxx 

element.o: element.cxx
	$(CC) $(FLAGS) element.cxx 

guardar.o: guardar.cxx
	$(CC) $(FLAGS) guardar.cxx 

simular_comandos.o: simular_comandos.cxx
	$(CC) $(FLAGS) simular_comandos.cxx 


clean:
	rm -f $(OBJS) $(OUT)
