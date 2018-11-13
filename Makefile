#Directories
SRCDIR := Sources
HEADDIR := Headers
OBJDIR := ObjectFiles
EXEDIR := Executables
RESDIR := Assets

#File extension
SRCEXT := cpp
OBJEXT := o
HEADEXT := h

SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
HEADERS := $(shell find $(HEADDIR) -type f -name *.$(HEADEXT))

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

#SEARCH_FLAGS tell preprocessor where to find header files
SEARCH_FLAGS = -I/usr/include/SDL2/ -I$(HEADDIR)/

#EXEC specifies the name of our executable
EXEC = $(EXEDIR)/HelloSDL

#This is the target that compiles our executable
$(EXEC) : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC)

#Instuctions for making the object files
$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(COMPILER_FLAGS) $(SEARCH_FLAGS) -c $< -o $@

#This is the target for running the compiled project
run : $(EXEC)
	$(EXEC)

#This deletes executable file and associated object files
clean:
	-rm -f $(EXEC) $(OBJS)