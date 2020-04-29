all: solve transform generate

solve:sudoku.o solve.o
	g++ -o solve sudoku.o solve.o

sudoku.o:sudoku.cpp sudoku.h
	g++ -c sudoku.cpp

solve.o:solve.cpp sudoku.h
	g++ -c solve.cpp

transform:sudoku.o transform.o
	g++ -o transform sudoku.o transform.o

transform.o:transform.cpp sudoku.h
	g++ -c transform.cpp

generate:generate.o
	g++ -o generate generate.o

generate.o:generate.cpp
	g++ -c generate.cpp

clean:
	rm solve transform generate *.o

