q1: q1.o
	g++ q1.o -o q1

q2_1: q2_1.o
	g++ q2_1.o -o q2_1
	
q2_3: q2_3.o
	g++ q2_3.o -o q2_3
	
q1.o: q1.cpp Sort.h
	g++ -c q1.cpp
	
q2_1.o: q2_1.cpp MinHeap.h
	g++ -c q2_1.cpp MinHeap.h
	
q2_3.o: q2_3.cpp MinHeap.h
	g++ -c q2_3.cpp MinHeap.h

all: q1 q2_1 q2_3