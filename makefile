hw: helloworld.o
	g++ helloworld.o -o hw

helloworld.o: helloworld.cpp log.hpp
	g++ -c helloworld.cpp

#log: log.cpp
#	g++ -c log.cpp

clean:
	rm *.o hw