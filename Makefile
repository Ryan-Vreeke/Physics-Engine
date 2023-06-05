CC=g++
LIB=`pkg-config --cflags gtkmm-3.0` `pkg-config --libs gtkmm-3.0`

main: Entity.o Matrix.o
	$(CC) -Wall -o main main.cpp Entity.o Matrix.o $(LIB) 

Entity.o: Entity.cpp
	$(CC) -c Entity.cpp $(LIB)

Matrix.o: Matrix.cpp
	$(CC) -c Matrix.cpp 

clean:
	rm -rf *.o main
