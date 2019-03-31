# code details
EXE_DIR = .
EXE = $(EXE_DIR)/ada

VPATH = SRC INCLUDE 
SRC= main.c parse.c

# compile to  object code
OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable
$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE)

# clean up compilation
clean:
	rm -f $(OBJ) $(EXE)

# dependencies
main.o: main.c parse.h
parse.o: parse.c
