target: t1 t2
	@echo "Building Target"
	g++ main linkedlist -o Lab10

t1: main.cpp function.h
	g++ -c main.cpp -o main

t2: linkedlist.cpp function.h
	g++ -c linkedlist.cpp -o linkedlist
	
all: target
