all :
	g++ .\src\main.cpp .\src\lineAlgorithm.cpp -o main -std=c++20 -O3

build-all:
	g++ -c .\src\lineAlgorithm.cpp -o lineAlgorithm.o -std=c++20 -O3 
	ar cr lineAlgorithm.lib lineAlgorithm.o
	del "lineAlgorithm.o"
	g++ .\src\main.cpp lineAlgorithm.lib -o main -std=c++20 -O3