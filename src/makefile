#OBJS	= main.o commands.o curiosity.o curiosity_movement.o util.o vector.o
OBJS	= main.o commands.o robot.o util.o
#SOURCE	= main.cxx curiosity/commands/commands.cxx curiosity/curiosity.cxx curiosity/movement/curiosity_movement.cxx util/util.cxx vector/vector.cxx
SOURCE	= main.cxx curiosity/commands/commands.cxx robot/robot.cxx util/util.cxx
#HEADER	= curiosity/commands/commands.h curiosity/curiosity.h curiosity/movement/curiosity_movement.h util/util.h vector/vector.h
HEADER	= curiosity/commands/commands.h robot/robot.h util/util.h
OUT		= main
CC		= g++
FLAGS	= -std=c++11 -g -c -Wall
LFLAGS	= 

main: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)
main.o: main.cxx
	$(CC) $(FLAGS) main.cxx 

commands.o: curiosity/commands/commands.cxx
	$(CC) $(FLAGS) curiosity/commands/commands.cxx 

robot.o: robot/robot.cxx
	$(CC) $(FLAGS) robot/robot.cxx
#curiosity.o: curiosity/curiosity.cxx
#	$(CC) $(FLAGS) curiosity/curiosity.cxx 

#curiosity_movement.o: curiosity/movement/curiosity_movement.cxx
#	$(CC) $(FLAGS) curiosity/movement/curiosity_movement.cxx 

util.o: util/util.cxx
	$(CC) $(FLAGS) util/util.cxx 

#vector.o: vector/vector.cxx
#	$(CC) $(FLAGS) vector/vector.cxx 


clean:
	rm -f $(OBJS) $(OUT)
