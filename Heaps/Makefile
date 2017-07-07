run: main.o util.o heap.o
	g++ -o run main.o util.o heap.o
		
main.o:	main.cpp util.hpp heap.hpp
	g++ -c main.cpp 

util.o: util.cpp util.hpp heap.hpp
	g++ -c util.cpp

heap.o:	heap.cpp heap.hpp
	g++ -c heap.cpp
	
clean:
	rm *.o

cleanAll:
	rm *.o run

