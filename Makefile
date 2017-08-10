#Main Makefile
CC = g++
CFLAGS = -g -Wall -MMD

#Binary
BIN = main

#Directories
IDIR = ./include
SDIR = ./src
ODIR = ./obj

#Paths
INCLUDE_PATHS = -I$(IDIR)

#Compilation line
COMPILE = $(CC) $(CFLAGS) $(INCLUDE_PATHS)

#FILEs
#---------------Include---------------#
INCS = $(wildcard $(IDIR)/*.hpp)
#---------------Source----------------#
SRCS = $(wildcard $(SDIR)/*.cpp)
#---------------Object----------------#
OBJS = $(SRCS:$(SDIR)/%.cpp=$(ODIR)/%.o)
#-------------Dependency--------------#
DEPS = $(SRCS:$(SDIR)/%.cpp=$(ODIR)/%.d)

all: $(OBJS)
	$(COMPILE) $(OBJS) main.cpp -o $(BIN)

# Include all .d files
-include $(DEPS)

$(ODIR)/%.o: $(SDIR)/%.cpp $(IDIR)/%.hpp
	$(COMPILE) -MMD -c $< -o $@ $(LIBS)

.PHONY : clean
clean :
	-rm $(BIN).d $(OBJS) $(DEPS)