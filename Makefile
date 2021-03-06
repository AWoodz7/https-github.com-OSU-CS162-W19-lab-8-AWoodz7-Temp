CC=g++ -g
EXE_FILE=matrix

all: $(EXE_FILE)

$(EXE_FILE): matrix.hpp size_mismatch.hpp application.o
	$(CC) matrix.hpp size_mismatch.hpp application.o -o $(EXE_FILE)


application.o: application.cpp
	$(CC) -c application.cpp

clean:
	rm -f *.hpp.gch *.o $(EXE_FILE)
