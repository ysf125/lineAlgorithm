all :
	g++ .\src\main.cpp lineAlgorithm.cpp -o main -std=c++20 -O3 
	.\main.exe

build :
	g++ -c .\src\lineAlgorithm.cpp -o lineAlgorithm.o
	ar cr lineAlgorithm.lib lineAlgorithm.o
	del "lineAlgorithm.o"
	g++ .\src\main.cpp lineAlgorithm.lib -o main -std=c++20 -O3 
	.\main.exe