a.out: compiler.o Variable.o
	g++ -std=c++17 compiler.o Variable.o -o a.out

compiler.o: compiler.cpp
	g++ -std=c++17 -c compiler.cpp

Variable.o: Variable.cpp 
	g++ -std=c++17 -c Variable.cpp

clean:
	rm *.o *.out 
