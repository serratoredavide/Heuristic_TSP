OBJS = main.o tsp.o utils.o heuristic_solver_TSP.o
HEADERS = tsp.h utils.h mystring.h heuristic_solver_TSP.h
HEADERS_DIR = /include/ 
EXE = exec_tsp
all: $(EXE) 
setting = -1   
OS := $(shell uname)

# ---------------------------------------------------------------------
# Compiler selection
# ---------------------------------------------------------------------
# 

ifeq ($(OS),Darwin)
	setting = 0
	CC = clang -Qunused-arguments
	AR = ar rc
	LIBS = -L.
	INC = -I. -I./$(HEADERS_DIR) 
endif

ifeq ($(OS),Linux)
	setting = 1
	CPLEX_HOME = /opt/ibm/ILOG/CPLEX_Studio1210/cplex
	CC = gcc
	AR = ar rc
	LIBS = -L.
	INC = -I. -I./$(HEADERS_DIR)
endif


# ---------------------------------------------------------------------
# Rules
# ---------------------------------------------------------------------
CFLAGS = -Wall -O3
RM = rm -rf

VPATH = ./include:./src

.SUFFIXES: .o .c
.c.o :
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(EXE): $(OBJS) $(LIBUTILS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS) $(LIBS)

$(OBJS) : $(HEADERS)

clean:
	$(RM) $(OBJS)
	$(RM) $(EXE) 
	$(RM) points
	
again:                                                               
	make clean
	make    

who:
	@echo "you are user $(USER) with uname `uname` (OS = $(OS)) and you working with compiler setting $(setting)" 

