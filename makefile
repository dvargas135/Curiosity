OBJS	= main.o commands.o curiosity.o util.o
SOURCE	= src/main.cxx src/curiosity/commands/commands.cxx src/robot/robot.cxx src/util/util.cxx
HEADER	= src/curiosity/commands/commands.h src/robot/robot.h src/util/util.h
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


clean:
	rm -f $(OBJS) $(OUT)
