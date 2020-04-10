q1: q1.o
	g++ q1.o -o q1

q2: q2.o
	g++ q2.o -o q2
	
q3: q3.o
	g++ q3.o -o q3
	
q4: q4.o
	g++ q4.o -o q4
	
q1.o: q1.cpp
	g++ -c q1.cpp
	
q2.o: q2.cpp
	g++ -c q2.cpp
	
q3.o: q3.cpp
	g++ -c q3.cpp
	
q4.o: q4.cpp OrderedMap.h
	g++ -c q4.cpp OrderedMap.h
	
all: q1 q2 q3 q4