#OBJS specifies which files to compile
OBJS = Main.o Game.o TextureManager.o

#My own headers
HEADERS = Game.h TextureManager.h

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

#SEARCH_FLAGS tell preprocessor where to find header files
SEARCH_FLAGS = -I/usr/include/SDL2/

#EXEC specifies the name of our executable
EXEC = HelloSDL

#This is the target that compiles our executable
$(EXEC) : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC)

#Instuctions for making the object files
.cpp.o: $(HEADERS)
	$(CC) $(COMPILER_FLAGS) $(SEARCH_FLAGS) -c $<

#This is the target for running the compiled project
run : $(EXEC)
	./$(EXEC)

#This deletes executable file and associated object files
clean:
	-rm -f $(EXEC) $(OBJS)