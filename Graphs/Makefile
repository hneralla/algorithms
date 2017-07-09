run: main.o util.o graph.o 
	g++ -o run main.o util.o graph.o 
		
main.o:	main.cpp util.hpp graph.hpp 
	g++ -c main.cpp 

util.o: util.cpp util.hpp graph.hpp
	g++ -c util.cpp
	
graph.o: graph.cpp graph.hpp 
	g++ -c graph.cpp
	
clean:
	rm *.o

cleanAll:
	rm *.o run


