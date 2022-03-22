CXXFLAGS = -Wall --std=c++17

all: main

main: component.o graph.o graphGenerator.o graphOperator.o main.o
	g++ $(CXXFLAGS) $^ -o PA2

component.o: component.cpp component.h
	g++ $(CXXFLAGS) -c component.cpp -o component.o

graph.o: graph.cpp graph.h
	g++ $(CXXFLAGS) -c graph.cpp -o graph.o

graphGenerator.o: graphGenerator.cpp graphGenerator.h
	g++ $(CXXFLAGS) -c graphGenerator.cpp -o graphGenerator.o

graphOperator.o: graphOperator.cpp graphOperator.h
	g++ $(CXXFLAGS) -c graphOperator.cpp -o graphOperator.o

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp -o main.o

run:
	./PA2 PA2_input/edges.txt PA2_input/hobbies.txt

#run:
	#./PA2 test/edges.txt test/hobbies.txt

.PHONY: clean
clean:
	rm *.o PA2
